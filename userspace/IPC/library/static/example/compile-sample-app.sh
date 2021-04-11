#!/bin/sh


gcc -I../../ library_shared_test.c -L ../ -lerror_utils  -o output.elf 



#‘-L’ specifies the library path.
#‘-l’ goes before the library name.

