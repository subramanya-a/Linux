SRC_PROCESS=library_shared_test.c
EXE_PROCESS=./output.elf
HEADER =../../ 
CFLAGS=-Wall -I../../ 
LIB_PATH=-L ../ -lerror_utils


all:
	gcc ${CFLAGS} ${SRC_PROCESS} $(LIB_PATH) -o ${EXE_PROCESS}
	
clean:
	rm -f ${EXE_PROCESS}
