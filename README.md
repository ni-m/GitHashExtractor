# GitHashExtractor
Use this repo to extract the current git hash and date information on compile time. 

## Installation
Run the following command in your local git repo:
```
git submodule add https://github.com/ni-m/GitHashExtractor
```

## Usage
### PlatformIO
Add the following lines to your platformio.ini file
```
extra_scripts = 
	pre:GitHashExtractor/firmwareVersion.py Cpp.h
```
### Qt creator with cmake
Add files to project source:
```
set(PROJECT_SOURCES
        [... your files ...]
        GitHashExtractor/firmwareVersion.py
        GitHashExtractor/version.h
)
```
Add the following lines to your CMakeLists.txt file 
```
# github.com/ni-m/gitHashExtractor
set(VERSION_FILE "./GitHashExtractor/version.h")
set(VERSION_PYTHON "./GitHashExtractor/firmwareVersion.py")
add_custom_command(OUTPUT ${VERSION_FILE}
    COMMAND python ${VERSION_PYTHON} [ARGS] [Qt.h]
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Creating ${VERSION_FILE}"
)

# target GitHashExtractor is always built
add_custom_target(GitHashExtractor ALL DEPENDS ${VERSION_FILE})
```

## Tool configuration
The following software versions were used to develop this software:
- VS Code
- Python 3.10.2
