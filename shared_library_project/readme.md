# Shared/Dynamic Library

### Make library files
`
make -f lib/lib_makefile
`

### Make app files and linking
`
make -f app/app_makefile
`

### Running app
Before running app (`./app/myApp`) do one of following

1. Copy the shared library (lib/*.so) to the application folder (not prefered)

2. Place the shared library file in one of the default library folders like /usr/local/lib, /usr/local/lib64, /usr/lib and /usr/lib64 (on Unix) or like C:\Windows\system32 and C:\Windows (on Windows)


3.  Add the folder of the library to the library search folders by setting path / environment variables:
    * Windows: Use PATH
    * Unix: Use LD_LIBRARY_PATH  
        * LD_LIBRARY_PATH=/full/path/to/library/directory:${LD_LIBRARY_PATH}
        * export LD_LIBRARY_PATH
    * Mac: Use DYLD_LIBRARY_PATH

4. We may also Dynamically Load / Unload a library at the run-time. This is known as late binding. This is achieved by using dlopen(), dlsym(), and dlclose() from dlfcn.h header
