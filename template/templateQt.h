/**
 * @file templateQt.h
 * @author ni-m
 * @brief Provides all information about versioning
 * 
 * firmwareVersion.py copies this file and replaces all #; saves the output into version.h
 * This template uses some Qt specific data types to simplify the usage
 * 
 * @date 2022-04-25
 * @copyright Copyright (c) 2022
 * 
 */

#include <QtCore>

//tag: GH_MAJOR.GH_MINOR.GH_PATCH GH_PRERELEASE offset: GH_OFFSET
namespace templateNamespace
{
    #ifndef GH_NO_URL
    QString gitURL = "GH_GITURL";
    #endif
    #ifndef GH_NO_TEXT
    QString gitHash = "GH_VERSION";
    QString BuildDate = "GH_DATE";
    QString BuildTime = "GH_TIME";
    #endif
    #ifndef GH_NO_RAW
	uint32_t buildTimeUnix = GH_UNIXTIME;
    char versionArray[] = {GH_MAJOR, GH_MINOR, GH_PATCH, GH_OFFSET}; //Major.Minor.Patch.Offset
    uint32_t gitHashHex = GH_GITHASHHEX;
    char dirtyFlag = GH_DIRTYFLAG;
    #endif
}
