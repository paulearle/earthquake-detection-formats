# PickJSON Format Specification

## Description

PickJSON is a format designed to encode the basic information of an unassociated
waveform arrival time pick.  PickJSON uses the
[JSON standard](http://www.json.org) .

## Usage
PickJSON is intended for use in seismic data messaging between seismic
applications and organizations.

## Output

    {
      "Type"      : "Pick",
      "ID"        : String,
      "SiteID"    : String,
      "Site"      :
      {
         "SiteID"    : String,
         "Station"   : String,
         "Channel"   : String,
         "Network"   : String,
         "Location"  : String
      },   
      "Time"      : ISO8601,
      "Source"    :
      {
         "AgencyID"  : String,
         "Author"    : String
      },
      "Phase"     : String,
      "Polarity"  : ("up" | "down"),
      "Onset"     : ("impulsive" | "emergent" | "questionable"),
      "Picker"    : ("manual" | "raypicker" | "filterpicker" | "earthworm" | "other"),
      "Filter"    : [Filter Objects ...]
      "Amplitude" :
      {
         "Amplitude" : Number,
         "Period"    : Number,
         "SNR"       : Number
      },
      "AssociationInfo" :
      {
         "Phase"    : String,
         "Distance" : Number,
         "Azimuth"  : Number,
         "Residual" : Number,
         "Sigma"    : Number
      }
    }

## Glossary
**Required Values:**

These are the values **required** to define a pick.
* Type - A string that identifies this message as a pick.
* ID - A string containing an unique identifier for this pick.
* Site - An object containing the station the pick was made at, see
[Site](https://gitlab.cr.usgs.gov/hydra/detection-formats/blob/master/Site.md).
* Source - An object containing the source of the pick, see
[Source](https://gitlab.cr.usgs.gov/hydra/detection-formats/blob/master/Source.md).
* Time - A string containing the UTC arrival time of the phase that was picked,
in the ISO8601 format `YYYY-MM-DDTHH:MM:SS.SSSZ`.

**Optional Values:**

The following are supplementary values that **may or may not** be provided by
various picking algorithms.
* Phase - A string that identifies the seismic phase that was picked.
* Polarity - A string containing the phase polarity; "up" or "down".
* Onset - A string containing the phase onset; "impulsive", "emergent", or
"questionable" .
* Picker - A string describing the type of picker; "manual", "raypicker",
"filterpicker", "earthworm", or "other".
* Filter - An array of objects containing the filter frequencies when the pick
was made, see
[Filter](https://gitlab.cr.usgs.gov/hydra/detection-formats/blob/master/Filter.md).
* Amplitude - An object containing the amplitude associated with the pick, see
[Amplitude](https://gitlab.cr.usgs.gov/hydra/detection-formats/blob/master/Amplitude.md).
* AssociationInfo - An object containing the association information if this
pick is used as data in an
[OriginJSON](https://gitlab.cr.usgs.gov/hydra/detection-formats/blob/master/OriginJSON.md),
see [Association](https://gitlab.cr.usgs.gov/hydra/detection-formats/blob/master/Association.md).