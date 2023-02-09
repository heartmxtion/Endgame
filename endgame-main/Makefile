
# set the compiler
CC := clang

# set the compiler flags
CFLAGS := `sdl2-config --libs --cflags` -ggdb3 -O0 -std=c11 -Wall -Wextra -Werror -Wpedantic -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm
# add header files here
INC := -I inc/*.h 

# add source files here
SRCS := src/*.c

EXEC := endgame

all: $(EXEC)
 
$(EXEC):
	$(CC) $(CFLAGS) -o $(EXEC) $(SRCS) $(INC)

clean:
	rm -f $(EXEC)

.PHONY: all clean

reinstall:
	make clean
	make
