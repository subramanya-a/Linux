#!/bin/sh


gcc -I../../ library_shared_test.c -L ../ -lerror_utils  -o output.elf 



#ā-Lā specifies the library path.
#ā-lā goes before the library name.

