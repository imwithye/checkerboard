CC= gcc -std=gnu99
CFLAGS= -O2 -Wall -Wextra -DLUA_COMPAT_5_2

all: lodepng.so

lodepng.so:	lodepng.o lua_lodepng.o
	$(CC) $(CFLAGS) -fPIC -llua -o lodepng.so -shared lodepng.o lua_lodepng.o

lua_lodepng.o: lua_lodepng.c
	$(CC) $(CFLAGS) -o lua_lodepng.o -c lua_lodepng.c

lodepng.o: lodepng.c lodepng.h
	$(CC) $(CFLAGS) -o lodepng.o -c lodepng.c

clean:
	rm -rf *.so *.o test_result_*

.PHONY: clean