SRC_PROCESS=pipes.c
EXE_PROCESS=pipes.elf
CFLAGS=-Wall -I../library/
#LIB_PATH=-L ../library/static/ -lerror_utils
LIB_PATH=-L ../library/shared/ -lerror_utils

all:
	gcc ${CFLAGS} ${SRC_PROCESS} $(LIB_PATH) -o ${EXE_PROCESS}

clean:
	rm -f ${EXE_PROCESS}
