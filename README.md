# GitHashExtractor

![GitHashExtractor Banner image](./doc/banner.svg)
Use this repo to extract the current git hash and date information on compile time. It supports various languages as stated in [utilization](#utilization)

## Requirements
Use one of the following schemas for your Git tags as described in [Semver2.0.0](https://semver.org/spec/v2.0.0.html)
```
1.2.2-alpha
1.2.2-alpha.3
1.2.2.alpha.beta
v2.3.4-beta
```

## Available variables
Name | Usage | Example | Flag to disable
-- | -- | -- | --
gitURL | The url of this GitRepo | username/repo | GH_NO_URL
gitVersion | info from git describe | v1.0.23-3-g354377c-dirty | GH_NO_TEXT
compDate | Date of compilation | 2021-09-19 | GH_NO_TEXT
compTime | Time of compilation | 17:06:40 | GH_NO_TEXT
compUnixTime | Unix timestamp of compilation | 1653459717 | GH_NO_RAW
tagArray | Array with Major.Minor.Patch | 1.0.23 | GH_NO_RAW
tagPreRelease | Prerelease as string | alpha / alpha.2 / alpha.beta | GH_NO_RAW
tagOffset | Amount of commits ahead this tag | 3 | GH_NO_RAW
gitHash | GitHash(n=7) as HexValue | 0x354377c | GH_NO_RAW
gitDirty | 1 for uncommited changes, else 0 | 1 | GH_NO_RAW

## Example [template](template/templateCpp.h) after build
```
namespace version
{
    #ifndef GH_NO_URL
	constexpr char gitURL[] = "";
    #endif
    #ifndef GH_NO_TEXT
	constexpr char gitVersion[] = "v1.1.1-0-gc184746-dirty";
	constexpr char compileDate[] = "2022-06-03";
	constexpr char compileTime[] = "12:28:27";
    #endif
    #ifndef GH_NO_RAW
	constexpr uint32_t compileUnixTime = 1654252107;
    constexpr char tagArray[] = {1, 1, 1, 0}; //Major.Minor.Patch.Offset
    constexpr char tagPreRelease[] = "";
    constexpr uint32_t gitHash = 0xc184746;
    constexpr char gitDirty = 1;
    #endif
}
```

## Installation
Run the following command in your local git repo: [Troubleshooting](#troubleshooting)
```
git submodule add https://github.com/ni-m/GitHashExtractor
```
## Utilization
### PlatformIO
Add the following lines to your platformio.ini file (uses default Cpp.h template)
```
extra_scripts = 
	pre:GitHashExtractor/firmwareVersion.py
build_flags =
  -D GH_NO_TEXT
```
***
### Qt creator with cmake
Add files to PROJECT_SOURCE:
```
set(PROJECT_SOURCES
        [... your files ...]
        GitHashExtractor/firmwareVersion.py
        GitHashExtractor/version.h
)
```
Add the following lines right after "set(PROJECT_SOURCES)" to your CMakeLists.txt file 
```
# START github.com/ni-m/gitHashExtractor
set(VERSION_FILE "./GitHashExtractor/version.h")
set(VERSION_PYTHON "./GitHashExtractor/firmwareVersion.py")
set_property(SOURCE ${VERSION_FILE} PROPERTY SKIP_AUTOGEN ON)
add_custom_command(OUTPUT ${VERSION_FILE}
    COMMAND python ${VERSION_PYTHON} [ARGS] [Qt.h]
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Creating ${VERSION_FILE}"
)

# target GitHashExtractor is always built
add_custom_target(GitHashExtractor ALL DEPENDS ${VERSION_FILE})
# END github.com/ni-m/gitHashExtractor
```
### Makefile
Add the following line to your target
```
python3 GitHubExtractor/firmwareVersion.py
```
## Tool configuration
The following software versions were used to develop this software:
- VS Code
- Python 3.10.2

## Troubleshooting
You may need to clone the submodule seperate after cloning your project.  
  
Problem with .gitignore: Add the following line to your .gitignore
```
!GitHashExtractor
```
Update submodule to latest version
```
git submodule update --remote
```
Init git submodule after submodule add
```
git submodule update --init
```
