hw2: shell.o parse.o builtin.o run_command.o is_background.o
	gcc shell.o parse.o builtin.o run_command.o is_background.o -o hw2
	
shell.o: shell.c shell.h
	gcc shell.c shell.h -c
	
parse.o: parse.c shell.h
	gcc parse.c shell.h -c
	
builtin.o: builtin.c shell.h
	gcc builtin.c shell.h -c
	
run_command.o: run_command.c shell.h
	gcc run_command.c shell.h -c
	
is_background.o: is_background.c shell.h
	gcc is_background.c shell.h -c
        
clean:
	rm *.o hw2 shell.h.gch
