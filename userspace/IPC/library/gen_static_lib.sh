#!/bin/sh

#Compile library files.
gcc -c error_utils.c -o error_utils.o  

# Create static library. This step is to bundle multiple object files in one static library.The output of this step is static library.
ar rcs ./static/liberror_utils.a error_utils.o
				    #‘c’  creates the archive. 
				    #‘r’  replaces or updates older files in the library. 
				    #'s'  Writes an object-file index into the archive



#An archive is a single file holding a collection of other files in a structure that makes it possible to retrieve the original individual files
