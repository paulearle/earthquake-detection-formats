# OriginJSON Format Specification

## Description

OriginJSON is a format designed to encode the basic information of an earthquake
event origin.  OriginJSON uses the [JSON standard](http://www.json.org).

## Usage
OriginJSON is intended for use in seismic data messaging between seismic
applications.

## Output

    {
      "Type"        : "Origin",
      "ID"          : String,
      "Source"      :
      {
         "AgencyID" : String,
         "Author"   : String
      },
      "Latitude"        : Number,
      "Longitude"       : Number,
      "Time"            : ISO8601,
      "Depth"           : Number,
      "DetectionType"   : String,
      "EventType"       : String,
      "Bayes"           : Number,
      "MinimumDistance" : Number,
      "RMS"             : Number,
      "Gap"             : Number,
      "Data"            : [PickJSON, BeamJSON, and / or CorrelationJSON Objects, ...]
    }

## Glossary
Required Values:
* Type - A string that identifies this message as a detection.
* ID - A string containing an unique identifier for this origin.
* Source - An object containing the source of the origin, see
[Source](Source.md).
* Latitude - A decimal number that identifies the latitude of the origin.
* Longitude - A decimal number that identifies the longitude of the origin.
* Depth - A decimal number that identifies the elevation of the origin.
* Time - A string containing the UTC origin time of the origin, in the ISO8601
format `YYYY-MM-DDTHH:MM:SS.SSSZ`.

Optional Values:
* DetectionType - A string that identifies whether the origin is `New`,
`Update`, `Final`, or `Retract`.
* EventType - A string containing the type of origin that was found;
`earthquake` or `blast`.
* Bayes - A decimal number that identifies bayesian statistic for this origin.
* Sigma - A decimal number indicating the standard deviation of the arrival time
measurement.
* Data - An array of [PickJSON](PickJSON.md), [BeamJSON](BeamJSON.md), and / or
[CorrelationJSON](CorrelationJSON.md) objects used to generate this origin.
* MinimumDistance - The minimum distance to the closest station.