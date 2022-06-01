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

#ifdef ARDUINO
    #include <Arduino.h>
#else
    #include <cstdint>
#endif

//tag: GH_MAJOR.GH_MINOR.GH_PATCH GH_PRERELEASE offset: GH_OFFSET
namespace templateNamespace
{
    #ifndef GH_NO_URL
	constexpr char gitURL[] = "GH_GITURL";
    #endif
    #ifndef GH_NO_TEXT
	constexpr char gitHash[] = "GH_VERSION";
	constexpr char BuildDate[] = "GH_DATE";
	constexpr char BuildTime[] = "GH_TIME";
    #endif
    #ifndef GH_NO_RAW
	constexpr uint32_t buildTimeUnix = GH_UNIXTIME;
    constexpr char versionArray[] = {GH_MAJOR, GH_MINOR, GH_PATCH, GH_OFFSET}; //Major.Minor.Patch.Offset
    constexpr uint32_t gitHashHex = GH_GITHASHHEX;
    constexpr char dirtyFlag = GH_DIRTYFLAG;
    #endif
}
