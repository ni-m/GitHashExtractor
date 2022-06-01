# @file firmwareVersion.py
# @author ni-m
# @brief Writes current github commit and build date/time into version.h for tracking
# Template can be chosen based on programming language

import subprocess
from datetime import date
from datetime import datetime
import time
import os
import inspect
import sys
import re

def log(msg):
    """ Write msg to console """
    print("firmwareVersion.py: " + msg)

def openTemplate(workingDir, lang, ending):
    """ Opens template and version.h """
    error = False
    try:
        # template, read only
        templateFile = open(workingDir + "template/template" + lang + ending, "r")

        # target file, overwrite
        versionFile = open(workingDir + "version" + ending, "w")                    
    except:
        error = True
        templateFile = False
        versionFile = False

    return templateFile, versionFile, error

def writeHash(templateFile, versionFile, workingDir):
    """
    Checks for valid git dir and writes git hash into version.h based on the template
    """
    # set working dir to parent for proper git hash
    # else it would extract the git hash of this submodule
    os.chdir(workingDir)
    os.chdir("../")

    # current date and time
    strDate = str(date.today())
    strTime = datetime.now().strftime("%H:%M:%S")
    unixTimeStamp = int(time.time())

    # get only git hash and dirty flag
    gitHashSub = subprocess.run(["git", "describe", "--always", "--dirty"], stdout=subprocess.PIPE, text=True)
    gitHash = gitHashSub.stdout.strip()

    # get gitURL
    gitURLSub = subprocess.run(["git", "config",  "--get", "remote.origin.url"], stdout=subprocess.PIPE, text=True)
    gitURL = gitURLSub.stdout.strip().replace("https://github.com/", "").replace(".git","")

    # get git hash , set flag --dirty if there are untracked changes
    buildVersionSub = subprocess.run(["git", "describe", "--tags", "--long"], stdout=subprocess.PIPE, text=True)
    buildVersion = buildVersionSub.stdout.strip()

    major = minor = patch = offset = dirtyFlag = error = 0
    preRelease = ''

    # set dirtyFlag if there are two elements
    gitHash = gitHash.split('-')
    if(len(gitHash) == 2):
        dirtyFlag = 1
    gitHashHex = hex(int(gitHash[0], 16))

    # extract correct tag and offset, else write gitHash
    if buildVersion != '':
        buildVersionArray = buildVersion.rsplit("-", 2)
        gitTag = buildVersionArray[0].replace("v","")
        offset = buildVersionArray[1]
        
        gitTagArray = re.split(r'[\-.]+', gitTag, 3)
        gitTagArray = list(filter(None, gitTagArray))

        try:
            major = gitTagArray[0]
            minor = gitTagArray[1]
            patch = gitTagArray[2]
            preRelease = gitTagArray[3]
        except:
            pass
    else:
        buildVersion = gitHash[0]
        error = 1

    buildVersion = buildVersion + dirtyFlag * "-dirty"

    log(buildVersion)
    # replace all variables in the template
    for line in templateFile:
        versionFile.write(line
        .replace('GH_GITURL', gitURL)
        .replace('GH_VERSION', buildVersion)
        .replace('GH_DATE', strDate)
        .replace('GH_TIME', strTime)
        .replace('GH_UNIXTIME', str(unixTimeStamp))
        .replace('templateNamespace', 'version')
        .replace('GH_MAJOR', str(major))
        .replace('GH_MINOR', str(minor))
        .replace('GH_PATCH', str(patch))
        .replace('GH_PRERELEASE', str(preRelease))
        .replace('GH_OFFSET', str(offset))
        .replace('GH_GITHASHHEX', str(gitHashHex))
        .replace('GH_DIRTYFLAG', str(dirtyFlag)))

    # close all files:
    templateFile.close()
    versionFile.close()
    return error

def getLanguage(workingDir):
    """
    Check for template files in ./template and compare the command line input for a valid template.
    Returns chosen env or default env (Cpp.h)
    """
    lang = "Cpp"
    ending = ".h"
    if len(sys.argv) == 2:
        os.chdir(workingDir)
        os.chdir("./template")
        langWithEnding = sys.argv[1]
        templates = os.listdir()
        for possibleLang in templates:
            if possibleLang == "template" + langWithEnding:
                langArray = langWithEnding.split('.')
                lang = langArray[0]
                ending = '.' + langArray[1]
                break
    return lang, ending

def main():
    '''
    Main code
    '''
    # get dir of this file -> prevent errors based on wrong working directory
    try:
        filename = inspect.getframeinfo(inspect.currentframe()).filename
        workingDir = os.path.dirname(os.path.abspath(filename)) + "/"
    except:
        workingDir = "./"
        log("Could not read working dir")
    lang, ending = getLanguage(workingDir)
    templateFile, versionFile, errorFileOpen = openTemplate(workingDir, lang, ending)

    if errorFileOpen:
        log("Template not found")
        return
    errorWriteHash = writeHash(templateFile, versionFile, workingDir)
    if errorWriteHash:
        log("No tag found")
        return
    log("Successfully updated for " + lang)
    return

#Not inside __main__ == __name__ to support PlatformIO
main()