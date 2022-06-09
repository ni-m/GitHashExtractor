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
        constexpr char gitVersion[] = "GH_VERSION";
        constexpr char compDate[] = "GH_DATE";
        constexpr char compTime[] = "GH_TIME";
    #endif
    #ifndef GH_NO_RAW
        constexpr uint32_t compUnixTime = GH_UNIXTIME;
        constexpr char tagArray[] = {GH_MAJOR, GH_MINOR, GH_PATCH}; //Major.Minor.Patch
        constexpr char tagPreRelease[] = "GH_PRERELEASE";
        constexpr char tagOffset = GH_OFFSET;
        constexpr uint32_t gitHash = GH_GITHASHHEX;
        constexpr char gitDirty = GH_DIRTYFLAG;
    #endif
}
