# @file firmwareVersion.py
# @author ni-m
# @brief Writes current github commit and build date/time into version.h for tracking
# Template can be chosen based on programming language

import subprocess
from datetime import date
from datetime import datetime
import os
import inspect
import sys

def log(msg):
    print("firmwareVersion.py: " + msg)

def openTemplate(workingDir, lang, ending):
    """Opens template and version.h"""
    error = False
    try:
        templateFile = open(workingDir + "template/template" + lang + ending, "r")     # template, read only
        versionFile = open(workingDir + "version" + ending, "w")                           # target file, overwrite
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

    # get git hash and gitURL, set flag --dirty if there are untracked changes
    buildVersionSub = subprocess.run(["git", "describe", "--tags", "--long", "--always", "--dirty"], stdout=subprocess.PIPE, text=True)
    buildVersion = buildVersionSub.stdout.strip()

    gitURLSub = subprocess.run(["git", "config",  "--get", "remote.origin.url"], stdout=subprocess.PIPE, text=True)
    gitURL = gitURLSub.stdout.strip()

    # check for empty string and set error flag in case it is not tracked under git
    error = False
    if buildVersion == '':
        buildVersion = gitURL = "Untracked"
        error = True

    log(buildVersion)

    # replace all variables in the template
    for line in templateFile:
        versionFile.write(line
        .replace('#GITURL', gitURL)
        .replace('#VERSION', buildVersion)
        .replace('#DATE', strDate)
        .replace('#TIME', strTime)
        .replace('templateNamespace', 'version'))

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
    log(workingDir)
    templateFile, versionFile, errorFileOpen = openTemplate(workingDir, lang, ending)
    if not errorFileOpen:
        errorWriteHash = writeHash(templateFile, versionFile, workingDir)
        if not errorWriteHash:
            log("Successfully updated for " + lang)
        else:
            log("Invalid git directory")
    else:
        log("Template not found")

#Not inside __main__ == __name__ to support PlatformIO
main()