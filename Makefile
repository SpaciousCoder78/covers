# Makefile for CALP
# License: GNU GPL-3
# Copyright (C) 2025 Aryan Karamtoth

install: src/main.c
	mkdir dist
	gcc src/main.c src/commands/calp_info.c -Wall -Wpedantic -Wextra -o dist/calp

clean:
	rm -rf dist  
