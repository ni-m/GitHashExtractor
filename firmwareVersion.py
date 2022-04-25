# @file firmwareVersion.py
# @author ni-m
# @brief Writes current github commit and build date/time into version.h for tracking

import subprocess
from datetime import date
from datetime import datetime

strToday = str(date.today())
now = datetime.now()

ret = subprocess.run(["git", "describe", "--tags", "--long", "--always", "--dirty"], stdout=subprocess.PIPE, text=True) #Uses any tags
build_version = ret.stdout.strip()
print ("Firmware Revision: " + build_version)
print("Today's date", strToday)
print("Today's time", now.strftime("%H:%M:%S"))

fin = open("./template/templateCpp.h", "r")   # template, read only
fout = open("./version.h", "w")          # target file, overwrite

# replace the following placeholders
#VERSION
#DATE
#TIME
# Template
for line in fin:
    fout.write(line.replace('#VERSION', build_version)
    .replace('#DATE', strToday)
    .replace('#TIME', now.strftime("%H:%M:%S"))
    .replace('NAMESPACE_ID', 'version'))
    
fin.close()
fout.close()