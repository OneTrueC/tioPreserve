INSTALLLOC = ~/.local/bin/

INC = -I. -I/usr/include
LIB =

CFLAGS = -O3 -Wall -Wextra -std=c99 -pedantic $(INC)
LDFLAGS = $(LIB)

all: build

build: tioPreserve.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(DEFSAVE) tioPreserve.c -o tioPreserve
	chmod +x tioPreserve

install: build
	cp tioPreserve $(INSTALLLOC)

clean:
	rm -f tioPreserve
