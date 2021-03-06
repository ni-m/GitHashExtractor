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
        QString gitVersion = "GH_VERSION";
        QString compDate = "GH_DATE";
        QString compTime = "GH_TIME";
    #endif
    #ifndef GH_NO_RAW
        constexpr uint32_t compUnixTime = GH_UNIXTIME;
        constexpr char tagArray[] = {GH_MAJOR, GH_MINOR, GH_PATCH}; //Major.Minor.Patch
        constexpr QString tagPreRelease = "GH_PRERELEASE";
        constexpr char tagOffset = GH_OFFSET;
        constexpr uint32_t gitHash = GH_GITHASHHEX;
        constexpr char gitDirty = GH_DIRTYFLAG;
    #endif
}
