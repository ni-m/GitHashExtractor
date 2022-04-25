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
    QString gitURL = "#GITURL";
    QString versionInfo = "#VERSION";
    QString BuildDate = "#DATE";
    QString BuildTime = "#TIME";
};
