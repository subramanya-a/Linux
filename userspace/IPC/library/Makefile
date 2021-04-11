SRC_PROCESS=error_utils.c
CFLAGS=-Wall
#static 
STATIC_LIB=error_utils.o
STATIC_LIB_EXPORT=liberror_utils.a

#shared
SHARED_LIB_EXPORT=liberror_utils.so
SHAREDFLAG=-shared -fPIC

#Export Path 
SHAREDPATH=./shared/
STATICPATH=./static/


all: static shared
#static:
	echo "Building static library"	
	#Compile library files.
	gcc -c $(SRC_PROCESS) -o $(STATIC_LIB)  

	# Create static library. This step is to bundle multiple object files in one static library.The output of this step is static library.
	ar rcs $(STATICPATH)$(STATIC_LIB_EXPORT) $(STATIC_LIB)
	#‘c’  creates the archive. 
	#‘r’  replaces or updates older files in the library. 
	#'s'  Writes an object-file index into the archive
	#An archive is a single file holding a collection of other files in a structure that makes it possible to retrieve the original individual files

#shared:
	echo "Building shared library"
	gcc $(SHAREDFLAG) ${CFLAGS} ${SRC_PROCESS} -o $(SHAREDPATH)${SHARED_LIB_EXPORT}
	#Copy library to standard lib path
	#sudo cp $(SHAREDPATH)$(SHARED_LIB_EXPORT) /usr/lib/

clean:
	rm -f $(STATICPATH)${STATIC_LIB_EXPORT}	
	rm -f $(SHAREDPATH)${SHARED_LIB_EXPORT}
	rm -f ${STATIC_LIB}	

	
