/**
 * @file templateQt.h
 * @author ni-m
 * @brief Provides all information about versioning
 * 
 * firmwareVersion.py copies this file and replaces all #; saves the output into version.h
 * 
 * @date 2022-04-25
 * @copyright Copyright (c) 2022
 * 
 */

#include <QtCore>

namespace templateNamespace
{
    #ifndef GH_NOURL
    QString gitURL = "#GITURL";
    #endif
    #ifndef GH_NOTEXT
    QString gitHash = "#VERSION";
    QString BuildDate = "#DATE";
    QString BuildTime = "#TIME";
    #endif
    #ifndef GH_NORAW
	uint32_t buildTimeUnix = #UNIXTIME;
    char versionArray[] = {#MAJOR, #MINOR, #PATCH, #OFFSET}; //Major.Minor.Patch.Offset
    uint32_t gitHashHex = #GITHASHHEX;
    char dirtyFlag = #DIRTYFLAG;
    #endif
};
