loadpng.so:	lua_loadpng.c
	gcc -fPIC -Wall -llua -shared -o loadpng.so lua_loadpng.c

clean:
	rm -rf *.so

.PHONY: clean