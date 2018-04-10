## MAKEFILE ##
FLAG = -ansi -std=c99 -Wall
SDIR = ./src/
ODIR = ./bin/

## Target to make BFile ##
help:
	@echo
	@echo "To make the BFile binary, type \"make BFile\" or just type \"make\""
	@echo

BFile: $(SDIR)BFile.c
	gcc $(FLAG) $(SDIR)BFile.c -o $(ODIR)BFile
