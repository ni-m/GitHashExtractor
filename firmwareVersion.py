# @file firmwareVersion.py
# @author ni-m
# @brief Writes current github commit and build date/time into version.h for tracking
# Template can be chosen based on programming language

import subprocess
from datetime import date
from datetime import datetime
import os.path

def openTemplate(workingDir, env = "Cpp"):
    try:
        templateFile = open(workingDir + "template/template" + env + ".h", "r")   # template, read only
        versionFile = open(workingDir + "version.h", "w")          # target file, overwrite
    except FileNotFoundError:
        templateFile = versionFile = False

    return templateFile, versionFile
        

def writeHash(templateFile, versionFile):
    strToday = str(date.today())
    now = datetime.now()

    ret = subprocess.run(["git", "describe", "--tags", "--long", "--always", "--dirty"], stdout=subprocess.PIPE, text=True)
    build_version = ret.stdout.strip()
    for line in templateFile:
        versionFile.write(line
        .replace('#VERSION', build_version)
        .replace('#DATE', strToday)
        .replace('#TIME', now.strftime("%H:%M:%S"))
        .replace('templateNamespace', 'version'))
    templateFile.close()
    versionFile.close()

def checkFolder():
    possibleDir = ["./", "../", "./GitHashExtractor"]
    workingDir = False

    for dir in possibleDir:
        if os.path.exists(dir + "firmwareVersion.py"):
            workingDir = dir
            break
    return workingDir

if __name__ == "__main__":
    workingDir = os.getcwd() + "/"
    if workingDir:
        templateFile, versionFile = openTemplate(workingDir)
        writeHash(templateFile, versionFile)
        print("Version.h updated")
    else:
        print("No template found")