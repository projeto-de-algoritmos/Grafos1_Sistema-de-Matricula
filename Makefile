# .bin
BINFOLDER := bin/
# .hpp
INCFOLDER := inc/
# .cpp
SRCFOLDER := src/
# .o
OBJFOLDER := obj/

CC := g++

CFLAGS := -W -Wall -O2 -Wextra -Wshadow -Wformat=2 -Wfloat-equal -pedantic -std=c++17 -DLOCAL

# any file with .cpp extension
SRCFILES := $(wildcard src/*.cpp)

# SRCFILES transforms .cpp files to .o files for the obj folder
all: create_folders $(SRCFILES:src/%.cpp=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/prog

# compiles the program class by class or file by file
obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc

create_folders:
	@mkdir -p $(OBJFOLDER) $(BINFOLDER)
run: bin/prog
	bin/prog

.PHONY: clean
clean:
	rm -Rf obj/*
	rm -Rf bin/*
