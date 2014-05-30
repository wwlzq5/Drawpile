Drawpile - a collaborative drawing program
------------------------------------------

DrawPile is a drawing program with a twist: you can share your drawing
live with other people.

Some feature highlights:

* Shared canvas using the built-in server or a dedicated server
* Record, play back and export drawing sessions
* Layers and blending modes
* Text layers
* Supports pressure sensitive Wacom tablets
* Built-in chat
* Supports OpenRaster file format
* Encrypted connections using SSL

## Building with cmake

Client dependencies:

* Qt 5.0 or newer
* [KF5 KArchive]
* [QtColorPicker]

Server dependencies:

* Qt 5.0 or newer (QtCore and QtNetwork only)
* libsystemd (optional)

It's a good idea to build in a separate directory to keep build files
separate from the source tree.

Example:

    $ mkdir build
    $ cd build
    $ cmake ..
    $ make

The executables will be generated in the `build/bin` directory. You can run them from there,
or install them with `make install`.

The configuration step supports some options:

* CLIENT=off: don't build the client (useful when building the stand-alone server only)
* SERVER=off: don't build the stand-alone server.
* CMAKE\_BUILD\_TYPE=debug: enable debugging features
* INITSYS="": select init system integration (currently only "systemd" is supported.) Set this to an empty string to disable all integration.

Example: `$ cmake .. -DDEBUG=on`

When compiling on Windows, cmake may complain about missing zlib. Setting the zlib path explicitly on the command line will solve this. For example:

    -DZLIB_LIBRARY:FILEPATH="C:\Qt\Tools\mingw48_32\lib\libz.a" -DZLIB_INCLUDE_DIR:PATH="C:\Qt\Tools\mingw48_32\include"



[KF5 KArchive]: https://projects.kde.org/projects/frameworks/karchive
[QtColorPicker]: https://github.com/mbasaglia/Qt-Color-Picker 

