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

//#MAJOR.#MINOR.#PATCH #PRERELEASE
namespace templateNamespace
{
	constexpr char gitURL[] = "#GITURL";
	constexpr char gitHash[] = "#VERSION";
	constexpr char BuildDate[] = "#DATE";
	constexpr char BuildTime[] = "#TIME";
    constexpr char versionArray[] = {#MAJOR, #MINOR, #PATCH, #OFFSET}; //Major.Minor.Patch.Offset
    constexpr uint32_t gitHashHex = #GITHASHHEX;
    constexpr char dirtyFlag = #DIRTYFLAG;
};
