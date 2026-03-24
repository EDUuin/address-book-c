OBJ:= $(patsubst %.c, %.o, $(wildcard *.c))

add.exe : $(OBJ)
	gcc -o $@ $^

clean :
	rm *.exe *.o
