#!/bin/sh

gcc -shared -fPIC error_utils.c -o  liberror_utils.so

#Copy library to standard lib path
sudo cp liberror_utils.so /usr/lib/


# '-fPIC' is used for shared libraries, allowing library code to be located anywhere in memory. 
# '-shared' instructs the compiler that we are building a shared library
