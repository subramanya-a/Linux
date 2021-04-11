SRC_PROCESS_A=FIFO_process_read.c
EXE_PROCESS_A=FIFO_process_read.elf
SRC_PROCESS_B=FIFO_process_write.c
EXE_PROCESS_B=FIFO_process_write.elf
CFLAGS=-Wall -I../library/
#LIB_PATH=-L ../library/static/ -lerror_utils
LIB_PATH=-L ../library/shared/ -lerror_utils

all: processA processB

processA: ${SRC_PROCESS_A}
	gcc ${CFLAGS} ${SRC_PROCESS_A} $(LIB_PATH) -o ${EXE_PROCESS_A}
processB: ${SRC_PROCESS_B}
	gcc ${CFLAGS} ${SRC_PROCESS_B} $(LIB_PATH) -o ${EXE_PROCESS_B}
clean:
	rm -f ${EXE_PROCESS_A} ${EXE_PROCESS_B}
