/**
 * @file exampleCpp.cpp
 * @author ni-m
 * @brief Example file for version tracking. 
 * Compile and run with attached makefile or run python script and compiler by yourself
 * 
 * @date 2022-06-03
 * @copyright Copyright (c) 2022
 * 
 */

#include "../version.h"

#include <iostream>
#include <iomanip>

int main(void)
{
    std::cout << "=========== version info ===========" << std::endl;
    std::cout << "Build date: " << version::compDate << std::endl;
    std::cout << "GitHash:    0x" << std::hex << version::gitHash << std::dec << std::endl;

    std::cout << "GitTag:     ";
    for(long unsigned int i = 0; i < 3; ++i)
    {
        // cast into int for proper display
        std::cout << (int)version::tagArray[i];
        if(i!=2){std::cout << ".";}
    }  
    std::cout << std::endl;

    std::cout << "Offset:     " << (int)version::tagOffset << std::endl;
    std::cout << "Prerelease: " << version::tagPreRelease << std::endl;
    std::cout << "Unixtime:   " << std::dec << version::compUnixTime << std::endl;
    return 0;
}