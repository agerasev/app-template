# Multi-build tool
This tool was planned as wrapper over graphical applications written with `C/C++` which allows to compile them for different platforms.
Now only two platforms are supported: `Desktop` and `Android`.
`SDL2` and `GLEW` libraries are used to support `Desktop` platforms (`Linux`, `Mac`, `Windows` and etc.).
For `Android` development you need `android-sdk` and `android-ndk` tools.

You can use this tool by running `bash` scripts from project directory:
+ `create <name> <author> <label>` creates directory `<name>` and puts needed files in it. Don't delete them. Source code must be placed in `source` directory. Build settings (compiler flags, libraries, files to compile) must be written in `build-info.mk` file.
+ `desktop/build` or `android/build` builds the project. `.apk` file for `Android` is located in `./android/bin/` directory. Binary file for `Desktop` is in `./desktop/` directory.
+ `desktop/run` or `android/run <device>` runs the builded application.
