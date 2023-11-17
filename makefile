CC = gcc
CFLAGS =-std=c17 -pedantic -Wall -fPIE -g -O0
LDFLAGS = -lm -lMLV
OBJ_DIR= obj/
OBJ = ${OBJ_DIR}graphic.o ${OBJ_DIR}process.o
EXE = bin/test
REG = src/

all : $(EXE)

$(EXE): $(REG)main.c $(OBJ)
	mkdir -p bin
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	

graphic.o: $(REG)graphic.c $(REG)graphic.h $(REG) process.h

process.o: $(REG)process.c $(REG)process.h


${OBJ_DIR}%.o: $(REG)%.c
	mkdir -p obj
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f obj/*
	rm -f $(EXE)

mrproper: clean
	rm -f $(EXE)
	rm -f $(TEST)