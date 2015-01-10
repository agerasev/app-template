# Multi-build tool
This tool was planned as wrapper over graphical applications written with `C/C++` which allows to compile them for different platforms.
Now only two platforms are supported: `PC` and `Android`.
`SDL2` and `GLEW` libraries are used to support `PC` platforms (`Linux`, `Mac`, `Windows` and etc.).
`Android API`, `JNI` and `GLES2` are used on `Android` platform.

For `PC` development are needed:
+ `gcc`/`g++`
+ `make`
+ `libsdl2`
+ `libglew`

For `Android` development you need `android-sdk` and `android-ndk` tools. I place them into `/opt` directory. If you will place them in other directory, you must change paths in `android/*` scripts.

You can use this tool by running `bash` scripts from project directory:
+ `create <name> <author> <activity>` creates directory `<name>` and puts needed files in it. Don't delete them. Source code must be placed in `source` directory. Build settings (compiler flags, libraries, files to compile) must be written in `build-info.mk` file.
+ `pc/build` or `android/build` builds the project. `.apk` file for `Android` is located in `./android/bin/` directory. Binary file for `PC` is in `./pc/` directory.
+ `pc/run` or `android/run <device>` runs the builded application.
