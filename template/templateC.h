#ifndef TEMPLATEC_H_
#define TEMPLATEC_H_

/**
 * @file templateCpp.h
 * @author ni-m
 * @brief Provides all information about versioning
 *
 * firmwareVersion.py copies this file and replaces all #; saves the output into version.h
 *
 * @date 2022-04-25
 * @copyright Copyright (c) 2022
 *
 */

#include "stdint.h"

// tag: GH_MAJOR.GH_MINOR.GH_PATCH GH_PRERELEASE offset: GH_OFFSET
#ifndef GH_NO_URL
static const uint8_t gitURL[] = "GH_GITURL";
#endif
#ifndef GH_NO_TEXT
static const uint8_t gitVersion[] = "GH_VERSION";
static const uint8_t compDate[] = "GH_DATE";
static const uint8_t compTime[] = "GH_TIME";
#endif
#ifndef GH_NO_RAW
static const uint32_t compUnixTime = GH_UNIXTIME;
static const uint8_t tagArray[] = {GH_MAJOR, GH_MINOR, GH_PATCH};  // Major.Minor.Patch
static const uint8_t tagPreRelease[] = "GH_PRERELEASE";
static const uint8_t tagOffset = GH_OFFSET;
static const uint32_t gitHash = GH_GITHASHHEX;
static const uint8_t gitDirty = GH_DIRTYFLAG;
#endif

#endif  // TEMPLATEC_H_
