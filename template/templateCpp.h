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

//tag: #MAJOR.#MINOR.#PATCH #PRERELEASE offset: #OFFSET
namespace templateNamespace
{
    #ifndef GH_NO_URL
	constexpr char gitURL[] = "#GITURL";
    #endif
    #ifndef GH_NO_TEXT
	constexpr char gitHash[] = "#VERSION";
	constexpr char BuildDate[] = "#DATE";
	constexpr char BuildTime[] = "#TIME";
    #endif
    #ifndef GH_NO_RAW
	constexpr uint32_t buildTimeUnix = #UNIXTIME;
    constexpr char versionArray[] = {#MAJOR, #MINOR, #PATCH, #OFFSET}; //Major.Minor.Patch.Offset
    constexpr uint32_t gitHashHex = #GITHASHHEX;
    constexpr char dirtyFlag = #DIRTYFLAG;
    #endif
}
