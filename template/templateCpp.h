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

namespace templateNamespace
{
const char gitURL[] = "#GITURL";
const char gitHash[] = "#VERSION";
const char BuildDate[] = "#DATE";
const char BuildTime[] = "#TIME";
};
