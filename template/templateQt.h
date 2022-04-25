/**
 * @file templateQt.h
 * @author ni-m
 * @brief Provides all information about versioning
 * 
 * firmwareVersion.py copies the file versionTemplate.h and replace all #; saves the output into version.h
 * 
 * @date 2022-04-25
 * @copyright Copyright (c) 2022
 * 
 */

#include <QtCore>

namespace templateNamespace
{
    QString versionInfo = "#VERSION";
    QString BuildDate = "#DATE";
    QString BuildTime = "#TIME";
};
