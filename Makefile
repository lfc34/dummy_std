.PHONY: static shared
CC = gcc
AFLAGS = -c -Wall -Wextra -Werror -std=c11 -Iinclude/
SOFLAGS = -c -fPIC -Wall -Wextra -Werror -std=c11 -Iinclude/

SOURCES = src/*.c 
OBJECTS = *.o

static:
	$(CC) $(AFLAGS) $(SOURCES)
	ar -rcs dummyc.a $(OBJECTS)
	rm *.o

shared:
	$(CC) $(SOFLAGS) $(SOURCES)
	$(CC) -shared $(OBJECTS) -o dummyc.so
	rm *.o