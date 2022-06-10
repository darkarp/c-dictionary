TARGET:=main
CC:=gcc
CFLAGS:=-g -Wall -Wextra -Werror -std=c11 -Wpedantic -MD -MP -fsanitize=address
LDLIBS:= -lm
SRC:=src
BIN:=bin
OBJ:=$(BIN)/obj
LIB:=dict

.DEFAULT_GOAL := help

# search subdirs for pattern
filesearch=	$(wildcard $1$2) $(foreach dir,$(wildcard $1*),$(call filesearch,$(dir)/,$2))

# check all subdirs for source files
SOURCES		:=	$(call filesearch,$(SRC),*.c)	
LIBSOURCES	:=	$(call filesearch,$(LIB),*.c)	
TESTSOURCES	:=	$(call filesearch,$(TEST),*.c)	

# remove main file					
SOURCES		:=	$(filter-out %$(TARGET).c, $(SOURCES))									
LIBSOURCES	:=	$(filter-out %test_io.c, $(LIBSOURCES))								
TESTSOURCES	:=	$(filter-out %test_io.c, $(TESTSOURCES))								

# build object list
OBJECTS:=	$(patsubst %.c, $(OBJ)/%.o, $(notdir $(SOURCES)))								
LIBOBJECTS:=	$(patsubst %.c, $(OBJ)/%.o, $(notdir $(LIBSOURCES)))								
TESTOBJECTS:=	$(patsubst %.c, $(OBJ)/%.o, $(notdir $(TESTSOURCES)))								

# Create output directories
create_output_directories:
	$(shell mkdir -p $(BIN))
	$(shell mkdir -p $(OBJ))

all: objects build tests ## Builds the project (compiles everything) and tests it

build: objects $(TARGET) ## Builds the project (compiles everything)
$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c $(CFLAGS) $^ -o $@

$(TARGET): $(SRC)/$(TARGET).c $(OBJECTS) $(LIBOBJECTS)
	@printf "\033[32m[i] Generating binary\033[0m\n"
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $(BIN)/$@

objects: create_output_directories
	@printf "\033[32m[i] Compiling library\033[0m\n"
$(OBJ)/%.o: $(LIB)/%.c
	$(CC) -c $(CFLAGS) $^ -o $@

clean: ## Deletes the build folder
	@printf "\033[33m[i] Deleting build folder: $(BIN)\033[0m\n"
	rm -rf $(BIN)

run: clean objects build ## Cleans, builds and runs the program
	./$(BIN)/$(TARGET)

.PHONY: tests
tests: ## Runs library tests
	@printf "\033[33m[i] Skipping tests: not implemented\033[0m\n"

.PHONY: help
help: ## Display this help message
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[32m%-20s\033[0m %s\n", $$1, $$2}'