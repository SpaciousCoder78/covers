# Makefile for CALP
# License: GNU GPL-3
# Copyright (C) 2025 Aryan Karamtoth

install: src/main.c
	mkdir dist
	gcc src/main.c src/commands/commands.c -Wall -Wpedantic -Wextra -o dist/clpm

clean:
	rm -rf dist  
