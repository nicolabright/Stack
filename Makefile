all:    stack.c
	gcc stack.c -o stack.exe
	@ cls
	@ stack.exe

clean:
	del stack.exe 2> nul
