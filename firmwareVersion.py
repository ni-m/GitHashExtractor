# @file firmwareVersion.py
# @author ni-m
# @brief Writes current github commit and build date/time into version.h for tracking
# Template can be chosen based on programming language

import subprocess
from datetime import date
from datetime import datetime
import os.path
from pathlib import Path
import inspect

def openTemplate(workingDir, env = "Cpp"):
    try:
        templateFile = open(workingDir + "template/template" + env + ".h", "r")   # template, read only
        versionFile = open(workingDir + "version.h", "w")          # target file, overwrite
    except FileNotFoundError:
        templateFile = versionFile = False

    return templateFile, versionFile

def writeHash(templateFile, versionFile, workingDir):
    # set working dir for proper git hash
    os.chdir(workingDir)
    os.chdir("..")

    # current date and time
    strDate = str(date.today())
    strTime = datetime.now().strftime("%H:%M:%S")

    # get git hash and gitURL, set flag --dirty if there are untracked changes
    try:
        buildVersionSub = subprocess.run(["git", "describe", "--tags", "--long", "--always", "--dirty"], stdout=subprocess.PIPE, text=True)
        buildVersion = buildVersionSub.stdout.strip()

        gitURLSub = subprocess.run(["git", "config",  "--get", "remote.origin.url"], stdout=subprocess.PIPE, text=True)
        gitURL = gitURLSub.stdout.strip()
    except:
        build_version = gitURL = "Untracked"

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

if __name__ == "__main__":
    # get dir of this file -> prevent errors based on wrong working directory
    filename = inspect.getframeinfo(inspect.currentframe()).filename
    workingDir     = os.path.dirname(os.path.abspath(filename)) + "/"
    print("firmwareVersion.py: " + workingDir)
    if workingDir:
        templateFile, versionFile = openTemplate(workingDir)
        writeHash(templateFile, versionFile, workingDir)
        print("firmwareVersion.py: Successfully updated")
    else:
        print("firmwareVersion.py: No template found")