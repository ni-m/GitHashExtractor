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

#include <cstdint>

//tag: #MAJOR.#MINOR.#PATCH #PRERELEASE offset: #OFFSET
namespace templateNamespace
{
    #ifndef GH_NOURL
	constexpr char gitURL[] = "#GITURL";
    #endif
    #ifndef GH_NOTEXT
	constexpr char gitHash[] = "#VERSION";
	constexpr char BuildDate[] = "#DATE";
	constexpr char BuildTime[] = "#TIME";
    #endif
    #ifndef GH_NORAW
	constexpr uint32_t buildTimeUnix = #UNIXTIME;
    constexpr char versionArray[] = {#MAJOR, #MINOR, #PATCH, #OFFSET}; //Major.Minor.Patch.Offset
    constexpr uint32_t gitHashHex = #GITHASHHEX;
    constexpr char dirtyFlag = #DIRTYFLAG;
    #endif
};
