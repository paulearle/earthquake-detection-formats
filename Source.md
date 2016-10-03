# Source Object Specification

## Description

The Source object is an object designed to define the originating seismic
organization that produced a [PickJSON](PickJSON.md), [BeamJSON](BeamJSON.md),
[CorrelationJSON](CorrelationJSON.md), or [OriginJSON](OriginJSON.md) message.  
Site uses the [JSON standard](http://www.json.org) .

## Usage
Source is intended for use as part of the [PickJSON](PickJSON.md),
[BeamJSON](BeamJSON.md), [CorrelationJSON](CorrelationJSON.md), or
[OriginJSON](OriginJSON.md) Formats in seismic data messaging between seismic
applications and organizations.

## Output

    {
      "AgencyID"  : String,
      "Author"    : String
    }

## Glossary
**Required Values:**

These are the values **required** to define a Source
* AgencyID - A string containing the originating agency FDSN ID.
* Author - A string containing the source author.