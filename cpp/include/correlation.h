/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_CORRELATION_H
#define DETECTION_CORRELATION_H

#include <string>

#include "hypocenter.h"
#include "site.h"
#include "source.h"
#include "associated.h"

namespace detectionformats {

/**
 * \brief detectionformats correlation conversion class
 *
 * The detectionformats correlation class is a conversion class used to create,
 * parse, and validate the unassociated correlation data format correlation.
 * The correlation format uses the JSON standard (www.json.org)
 *
 * correlation is intended for use in seismic data messaging between seismic
 * applications and organizations.
 *
 * correlation uses the Source and Site common objects.
 */
class correlation: public detectionbase {
public:
	/**
	 * \brief correlation constructor
	 *
	 * The constructor for the correlation class.
	 * Initilizes members to null values.
	 */
	correlation();

	/**
	 * \brief correlation advanced constructor
	 *
	 * The advanced constructor for the correlation class.
	 * Initilizes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newstation - A std::string containing the station to use
	 * \param newchannel - A std::string containing the channel to use
	 * \param newnetwork - A std::string containing the network to use
	 * \param newlocation - A std::string containing the location to use
	 * \param newagencyid - A std::string containing the agencyid to use
	 * \param newauthor - A std::string containing the author to use
	 * \param newphase - A std::string containing the phase to use
	 * \param newtime - A double containing the new phase time to use
	 * \param newcorrelation - A double containing the correlation value to use
	 * \param newlatitude - A double containing the latitude to use
	 * \param newlongitude - A double containing the longitude to use
	 * \param neworigintime - A double containing the new origin time to use
	 * \param newdepth - A double containing the depth to use
	 * \param newlatitudeerror - A double containing the latitude error to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newlongtiudeerror - A double containing the longitude error to
	 * 		use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newtimeerror - A double containing the time error to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newdeptherror - A double containing the depth error to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param neweventtype - A std::string containing the event type to use,
	 * 		empty string to omit
	 * \param newmagnitude - A double containing the magnitude to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newsnr - A double containing the snr to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newzscore - A double containing the zscore to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newdetectionthreshold - A double containing the detection
	 * 		threshold to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newthresholdtype - A std::string containing the threshold type to
	 * 		use, empty string to omit
	 */
	correlation(std::string newid, std::string newstation,
			std::string newchannel, std::string newnetwork,
			std::string newlocation, std::string newagencyid,
			std::string newauthor, std::string newphase, double newtime,
			double newcorrelation, double newlatitude, double newlongitude,
			double neworigintime, double newdepth, double newlatitudeerror,
			double newlongitudeerror, double newtimeerror, double newdeptherror,
			std::string neweventtype, double newmagnitude, double newsnr,
			double newzscore, double newdetectionthreshold,
			std::string newthresholdtype);

	/**
	 * \brief correlation advanced constructor
	 *
	 * The advanced constructor for the correlation class.
	 * Initilizes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newstation - A std::string containing the station to use
	 * \param newchannel - A std::string containing the channel to use
	 * \param newnetwork - A std::string containing the network to use
	 * \param newlocation - A std::string containing the location to use
	 * \param newagencyid - A std::string containing the agencyid to use
	 * \param newauthor - A std::string containing the author to use
	 * \param newphase - A std::string containing the phase to use
	 * \param newtime - A double containing the new phase time to use
	 * \param newcorrelation - A double containing the correlation value to use
	 * \param newlatitude - A double containing the latitude to use
	 * \param newlongitude - A double containing the longitude to use
	 * \param neworigintime - A double containing the new origin time to use
	 * \param newdepth - A double containing the depth to use
	 * \param newlatitudeerror - A double containing the latitude error to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newlongtiudeerror - A double containing the longitude error to
	 * 		use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newtimeerror - A double containing the time error to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newdeptherror - A double containing the depth error to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param neweventtype - A std::string containing the event type to use,
	 * 		empty string to omit
	 * \param newmagnitude - A double containing the magnitude to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newsnr - A double containing the snr to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newzscore - A double containing the zscore to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newdetectionthreshold - A double containing the detection
	 * 		threshold to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newthresholdtype - A std::string containing the threshold type to
	 * 		use, empty string to omit
	 * \param newassociatedphase - A std:string containing the associated phase
	 * 		to use, empty string to omit
	 * \param newassociateddistance - A double containing the associated
	 * 		distance to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newassociatedazimuth - A double containing the associated azimuth
	 * 		to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newassociatedresidual - A double containing the associated
	 * 		residual to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newassociatedsigma - A double containing the associated sigma to
	 * 		use, std::numeric_limits<double>::quiet_NaN() to omit
	 */
	correlation(std::string newid, std::string newstation,
			std::string newchannel, std::string newnetwork,
			std::string newlocation, std::string newagencyid,
			std::string newauthor, std::string newphase, double newtime,
			double newcorrelation, double newlatitude, double newlongitude,
			double neworigintime, double newdepth, double newlatitudeerror,
			double newlongitudeerror, double newtimeerror, double newdeptherror,
			std::string neweventtype, double newmagnitude, double newsnr,
			double newzscore, double newdetectionthreshold,
			std::string newthresholdtype, std::string newassociatedphase,
			double newassociateddistance, double newassociatedazimuth,
			double newassociatedresidual, double newassociatedsigma);

	/**
	 * \brief correlation alternate advanced constructor
	 *
	 * The alternate advanced constructor for the correlation class.
	 * Initilizes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newsite - A detectionformats::site containing the site to use
	 * \param newsource - A detectionformats::source containing the source to
	 * 		use
	 * \param newphase - A std::string containing the phase to use
	 * \param newtime - A double containing the new phase time to use
	 * \param newcorrelation - A double containing the correlation value to use
	 * \param newhypocenter - A detectionformats::hypocenter containing the hypocenter
	 * 		to use
	 * \param neweventtype - A std::string containing the event type to use,
	 * 		empty string to omit
	 * \param newmagnitude - A double containing the magnitude to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newsnr - A double containing the snr to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newzscore - A double containing the zscore to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newdetectionthreshold - A double containing the detection
	 * 		threshold to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newthresholdtype - A std::string containing the threshold type to
	 * 		use, empty string to omit
	 */
	correlation(std::string newid, detectionformats::site newsite,
			detectionformats::source newsource, std::string newphase,
			double newtime, double newcorrelation,
			detectionformats::hypocenter newhypocenter,
			std::string neweventtype, double newmagnitude, double newsnr,
			double newzscore, double newdetectionthreshold,
			std::string newthresholdtype);

	/**
	 * \brief correlation alternate advanced constructor
	 *
	 * The alternate advanced constructor for the correlation class.
	 * Initilizes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newsite - A detectionformats::site containing the site to use
	 * \param newsource - A detectionformats::source containing the source to
	 * 		use
	 * \param newphase - A std::string containing the phase to use
	 * \param newtime - A double containing the new phase time to use
	 * \param newcorrelation - A double containing the correlation value to use
	 * \param newhypocenter - A etectionformats::hypocenter containing the hypocenter
	 * 		to use
	 * \param neweventtype - A std::string containing the event type to use,
	 * 		empty string to omit
	 * \param newmagnitude - A double containing the magnitude to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newsnr - A double containing the snr to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newzscore - A double containing the zscore to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newdetectionthreshold - A double containing the detection
	 * 		threshold to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newthresholdtype - A std::string containing the threshold type to
	 * 		use, empty string to omit
	 * \param newassociated - A detectionformats::associated containing the
	 * 		associated to use
	 */
	correlation(std::string newid, detectionformats::site newsite,
			detectionformats::source newsource, std::string newphase,
			double newtime, double newcorrelation,
			detectionformats::hypocenter newhypocenter,
			std::string neweventtype, double newmagnitude, double newsnr,
			double newzscore, double newdetectionthreshold,
			std::string newthresholdtype,
			detectionformats::associated newassociated);

	/**
	 * \brief correlation advanced constructor
	 *
	 * The advanced constructor for the correlation class.
	 * Converts the provided object from a json::Object, populating members
	 * \param jsondocument - A json document.
	 */
	correlation(rapidjson::Value &json);

	/**
	 * \brief correlation copy constructor
	 *
	 * The copy constructor for the correlation class.
	 * Copys members from provided correlation.
	 *
	 * \param newcorrelation - A detectionformats::correlation to copy from
	 */
	correlation(const correlation &newcorrelation);

	/**
	 * \brief correlation destructor
	 *
	 * The destructor for the correlation class.
	 */
	~correlation();

	/**
	 * \brief Convert to json object function
	 *
	 * Converts the contents of the class to a json object
	 * \return Returns a json::Object containing the class contents
	 */
	virtual rapidjson::Value & tojson(rapidjson::Value &json,
			rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator)
					override;

	/**
	 * \brief Gets any errors in the class
	 *
	 * Gets any formatting errors in the class
	 * \return Returns a std::vector<std::string> containing the errors
	 */
	virtual std::vector<std::string> geterrors() override;

	/**
	 * \brief correlation id
	 *
	 * A required std::string containing the id of this correlation message
	 */
	std::string id;

	/**
	 * \brief correlation site
	 *
	 * A required detectionformats::site containing the site for this
	 * correlation message
	 */
	detectionformats::site site;

	/**
	 * \brief correlation source
	 *
	 * A required detectionformats::source containing the source for this
	 * correlation message
	 */
	detectionformats::source source;

	/**
	 * \brief correlation phase
	 *
	 * A required std::string containing the phase for this correlation message
	 */
	std::string phase;

	/**
	 * \brief correlation phase time
	 *
	 * A required double containing the phase time for this correlation message
	 */
	double time;

	/**
	 * \brief correlation value
	 *
	 * A required double defining the correlation value for this correlation
	 * message
	 */
	double correlationvalue;

	/**
	 * \brief correlation hypocenter
	 *
	 * A required detectionformats::hypocenter defining the hypocenter of this
	 * correlation message
	 */
	detectionformats::hypocenter hypocenter;

	/**
	 * \brief correlation event type
	 *
	 * An optional std::string containing the event type of this correlation
	 * message valid values are "earthquake" or "blast"
	 */
	std::string eventtype;

	/**
	 * \brief magnitude value
	 *
	 * An optional double defining the magnitude for this correlation message
	 */
	double magnitude;

	/**
	 * \brief correlation snr value
	 *
	 * An optional double defining the snr for this correlation message
	 */
	double snr;

	/**
	 * \brief correlation zscore value
	 *
	 * An optional double defining the zscore for this correlation message
	 */
	double zscore;

	/**
	 * \brief correlation detection threshold value
	 *
	 * An optional double defining the detection threshold for this correlation
	 * message
	 */
	double detectionthreshold;

	/**
	 * \brief correlation threshold type
	 *
	 * An optional std::string defining the threshold type of  this correlation
	 *  message
	 */
	std::string thresholdtype;

	/**
	 * \brief correlation associated
	 *
	 * Optional detectionformats::associated containing the associated
	 * information for this correlation message
	 */
	detectionformats::associated associationinfo;

protected:

};
}
#endif
