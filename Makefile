all: snconverter

WARNINGS = -Wall
DEBUG = -ggdb -fno-omit-frame-pointer
OPTIMIZE = -O2
OPTS = -lm

snconverter: Makefile snconverter.c
	$(CC) -o $@ $(WARNINGS) $(DEBUG) $(OPTIMIZE) $(OPTS) snconverter.c

clean:
	rm -f snconverter

install:
	echo "Installing is not supported"

run:
	./snconverter

