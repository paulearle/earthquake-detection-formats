cmake_minimum_required (VERSION 3.4)

# ----- VERSION NUMBER----- #
set(VERSION_MAJOR 0)
set(VERSION_MINOR 9)
set(VERSION_PATCH 0)

# ----- PROJECT ----- #
project (DetectionFormats VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

include(internal_utils.cmake)

fix_default_compiler_settings()  # Defined in internal_utils.cmake.

# ----- NON WINDOWS CONFIG ----- #
if (NOT MSVC)
    # C++ 14 Standard
    SET(GCC_CXX_14_FLAGS "-std=c++14")
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_CXX_14_FLAGS} ")

    option(SUPPORT_COVERAGE "Instrument for Coverage" ON)

    if(SUPPORT_COVERAGE)
        # Coverage
        SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
        SET(GCC_COVERAGE_LINK_FLAGS "--coverage")

        # set flags
        SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_CXX_14_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
        SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
    endif (SUPPORT_COVERAGE)
endif (NOT MSVC)

# ----- CMAKE CONFIG HEADER ----- #
# pass some of the CMake settings
# to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/DetectionFormatsCMakeConfig.h.in"
    "${PROJECT_BINARY_DIR}/DetectionFormatsCMakeConfig.h"
)

# ----- EXTERNAL LIBRARIES ----- #
# rapidjson
set(RAPIDJSON_PATH "${CURRENT_SOURCE_DIR}/lib/rapidjson" CACHE PATH "Path to rapidjson")

# ----- SET INCLUDE DIRECTORIES ----- #
include_directories(${PROJECT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${RAPIDJSON_PATH}/..)
include_directories(${RAPIDJSON_PATH})

# ----- SET SOURCE FILES ----- #
file(GLOB SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)

# ----- SET HEADER FILES ----- #
file(GLOB HDRS ${PROJECT_SOURCE_DIR}/include/*.h)

# ----- CREATE LIBRARY ----- #
add_library (DetectionFormats STATIC ${SRCS} ${HDRS})

# ----- TARGET PROPERTIES ----- #
set_target_properties(DetectionFormats PROPERTIES
    OUTPUT_NAME DetectionFormats)

# ----- GENERATE ----- #
include(GenerateExportHeader)
generate_export_header(DetectionFormats EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/DetectionFormats_export.h)

# ----- GLOBAL INCLUDES ----- #
target_include_directories(
    DetectionFormats PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

# ----- TESTS ----- #
option(RUN_TESTS "Create and run unit tests (requires GTest)" OFF)

if (RUN_TESTS)

    # ----- LOOK FOR GTEST ----- #
    set(GTEST_ROOT "./" CACHE PATH "Path to the google test library")
    find_package(GTest REQUIRED)

    enable_testing()

    # ----- TEST SOURCES ----- #
    file(GLOB UNITTEST_SOURCES ${PROJECT_SOURCE_DIR}/tests/*.cpp)

    if (NOT MSVC)
        set(PTHREADLIB -pthread)
    endif (NOT MSVC)

    # ----- SET TEST INCLUDE DIRECTORIES ----- #
    include_directories(${GTEST_INCLUDE_DIRS})

    # ----- CREATE TEST EXE ----- #
    add_executable(DetectionFormatsTests ${UNITTEST_SOURCES})
    set_target_properties(DetectionFormatsTests PROPERTIES OUTPUT_NAME DetectionFormats-tests)
    target_link_libraries(DetectionFormatsTests ${PTHREADLIB} ${GCC_COVERAGE_LINK_FLAGS} ${GTEST_BOTH_LIBRARIES})
    target_link_libraries(DetectionFormatsTests DetectionFormats)

    # ----- TESTS ----- #
    GTEST_ADD_TESTS(DetectionFormatsTests "" ${UNITTEST_SOURCES})

    # ----- RUN TESTS ----- #
    add_custom_command(TARGET DetectionFormatsTests
        POST_BUILD
        COMMAND DetectionFormatsTests
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Running DetectionFormatsTests" VERBATIM
    )

    # ----- RUN COVERAGE ----- #
    if(SUPPORT_COVERAGE)

        option(RUN_COVERAGE "Run Coverage Report (requires lcov installed)" OFF)

        if(RUN_COVERAGE)
            add_custom_target(coverage-report ALL
              DEPENDS DetectionFormatsTests
              COMMAND /bin/sh
              ${PROJECT_SOURCE_DIR}/generate_coverage.sh
              COMMENT "Capture/Report Coverage Info" VERBATIM
            )

        endif (RUN_COVERAGE)

    endif (SUPPORT_COVERAGE)
endif()

# ----- CPPCHECK ----- #
option(RUN_CPPCHECK "Run CPP Checks (requires cppcheck installed)" OFF)

if(RUN_CPPCHECK)

    file(GLOB CPPCHECK_SRCS "${PROJECT_SOURCE_DIR}/include/*.h" "${PROJECT_SOURCE_DIR}/src/*.cpp")

    add_custom_target(cppcheck ALL
      DEPENDS DetectionFormats
      COMMAND cppcheck
      --enable=warning,performance,portability
      --language=c++
      --std=c++11
      --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)"
      --verbose
      --suppress=nullPointerRedundantCheck
      --error-exitcode=1
      ${CPPCHECK_SRCS}
      COMMENT "Running cppcheck" VERBATIM
    )
endif()

# ----- CPPLINT ----- #
option(RUN_CPPLINT "Run CPP Checks (requires cpplint and python installed)" OFF)

if(RUN_CPPLINT)

    set(CPPLINT_PATH "${CURRENT_SOURCE_DIR}/lib/cpplint/cpplint.py" CACHE FILEPATH "Path to cpplint")
    file(GLOB CPPLINT_SRCS "${PROJECT_SOURCE_DIR}/include/*.h" "${PROJECT_SOURCE_DIR}/src/*.cpp")

    add_custom_target(cpplint ALL
      DEPENDS DetectionFormats
      COMMAND "${CPPLINT_PATH}"
      --filter=-whitespace/tab,-legal/copyright,-build/c++11
      ${CPPCHECK_SRCS}
      COMMENT "Running cpplint" VERBATIM
    )
endif()

# ----- DOCUMENTATION ----- #
option(GENERATE_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" OFF)

if(GENERATE_DOCUMENTATION)

    # ----- LOOK FOR DOXYGEN ----- #
    find_package(Doxygen REQUIRED)

    set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${doxyfile_in} ${doxyfile} @ONLY)

    add_custom_target(doc ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)

    install(
        DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html
        DESTINATION doc/${PROJECT_NAME}
    )
endif()

# ----- INSTALL RULES ----- #
# Layout. This works for all platforms:
#   * <prefix>/lib/<PROJECT-NAME>
#   * <prefix>/lib/
#   * <prefix>/include/
set(config_install_dir "lib/${PROJECT_NAME}")
set(include_install_dir "include")

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

# ----- Configuration ----- #
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(targets_export_name "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

# Include module with function 'write_basic_package_version_file'
include(CMakePackageConfigHelpers)

# Configure '<PROJECT-NAME>ConfigVersion.cmake'
# Note: PROJECT_VERSION is used as a VERSION
write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
)

# Configure '<PROJECT-NAME>Config.cmake'
# Use variables:
#   * targets_export_name
#   * PROJECT_NAME
configure_package_config_file(
    "Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
)

# Targets:
#   * <prefix>/lib/libDetectionFormats.a
#   * header location after install: <prefix>/include/*.h
install(
    TARGETS DetectionFormats
    EXPORT "${targets_export_name}"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    INCLUDES DESTINATION "${include_install_dir}"
)

# Headers:
#   * *.h-> <prefix>/include/*.h
install(
    FILES ${HDRS}
    DESTINATION "${include_install_dir}/${PROJECT_NAME}"
)

install(
    DIRECTORY ${RAPIDJSON_PATH}
    DESTINATION "${include_install_dir}"
    )

# Export headers:
#   * ${CMAKE_CURRENT_BINARY_DIR}/DetectionFormats_export.h -> <prefix>/include/DetectionFormats_export.h
install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/DetectionFormats_export.h"
    DESTINATION "${include_install_dir}"
)

# Config
#   * <prefix>/lib/DetectionFormats/DetectionFormatsConfig.cmake
#   * <prefix>/lib/DetectionFormats/DetectionFormatsConfigVersion.cmake
install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)

# Config
#   * <prefix>/lib/DetectionFormats/DetectionFormatsTargets.cmake
install(
    EXPORT "${targets_export_name}"
    NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
)
