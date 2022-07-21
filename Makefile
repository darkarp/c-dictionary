TARGET=main
CC=gcc
CFLAGS=-g -Wall -Wextra -Werror -std=c11 -Wpedantic
LDLIBS= -lm
SRC=src
BIN=bin
OBJ=$(BIN)/obj
LIB=dict
LIB_SOURCES=$(LIB)/dict.c $(LIB)/hashutils.c $(LIB)/node.c $(LIB)/prime.c
OBJ_SOURCES=$(OBJ)/dict.o $(OBJ)/hashutils.o $(OBJ)/node.o $(OBJ)/prime.o

all: $(OBJ) $(OBJ_SOURCES) $(TARGET).exe
	@echo [+] Finished building
$(OBJ_SOURCES): $(LIB)/*.c
	$(CC) -c $(CFLAGS) $(LIB)/$(*F).c -o $*.o

$(OBJ):
	@mkdir "$(OBJ)";

$(TARGET).exe: $(SRC)/$(TARGET).c $(OBJ_SOURCES)
		$(CC) $(CFLAGS) $? $(LDLIBS) -o $(BIN)/$@
	
clean: $(OBJ)
	@cmd.exe /q /s /c rmdir /q /s $(BIN)
	@echo [+] Clean completed
	

help:
	@echo "nmake all:	builds entire program"
	@echo "nmake clean:	cleans the bin directory"