# Makefile for covers
# License: MIT
# Copyright (C) 2025 Aryan Karamtoth

install: src/main.c
	mkdir dist
	gcc src/main.c src/commands/commands.c -Wall -Wpedantic -Wextra -o  dist/covers -fsanitize=address,undefined,bounds -g3

clean:
	rm -rf dist  

root: src/main.c
	sudo gcc src/main.c src/commands/commands.c -o /usr/local/bin/covers

rootrm:
	sudo rm /usr/local/bin/covers
