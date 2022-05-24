# GitHashExtractor
Use this repo to extract the current git hash and date information on compile time. It supports various languages as stated in [utilization](#utilization)

## Requirements
Use one of the following schemas for your Git tags as described in [Semver2.0.0](https://semver.org/spec/v2.0.0.html)
```
1.2.2-alpha
1.2.2-alpha.3
1.2.2.alpha.beta
v.2.3.4-beta
```

## Available expressions
Expression | Usage | Example
-- | -- | --
#GITURL | The url of this GitRepo | www.github.com/username/repo
#VERSION | tag-offset-gitHash-dirtyFlag from git describe | v1.0.23-3-g354377c-dirty
#DATE | Date of compilation | 2021-09-19
#TIME | Time of compilation | 17:06:40
#MAJOR | Major version | 1
#MINOR | Minor version | 1
#PATCH | Patch | 23
#PRERELEASE | Prerelease | alpha / alpha.2 / alpha.beta
#OFFSET | Amount of commits ahead this tag | 3
#GITHASHHEX | GitHash(7) as HexValue | 0x354377c
#DIRTYFLAG | 1 for uncommited changes, else 0 | 1

## Example [template](template/templateCpp.h) after build
```
namespace version
{
	constexpr char gitURL[] = "www.github.com/username/repo";
	constexpr char gitHash[] = "v1.0.23-3-g354377c-dirty";
	constexpr char BuildDate[] = "2021-09-19";
	constexpr char BuildTime[] = "17:06:40";
    constexpr char versionArray[] = {1, 0, 23, 3}; //Major.Minor.Patch.Offset
    constexpr uint32_t gitHashHex = 0x354377c;
    constexpr char dirtyFlag = 1;
};
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

## Tool configuration
The following software versions were used to develop this software:
- VS Code
- Python 3.10.2

## Troubleshooting
You may need to clone the submodule seperate after cloning your project.  
  
Problem with GitIgnore: Add the following line to your .gitignore
```
!GitHashExtractor
```
Update submodule to latest version
```
git submodule update --remote
```
Init git submodule after submodule add
```
git init
```
