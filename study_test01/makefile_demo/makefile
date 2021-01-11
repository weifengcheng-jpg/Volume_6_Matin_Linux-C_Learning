
objects = hellospeak.o speak.o
hello_demo : $(objects)
	gcc -o -g hello_demo $(objects)

$(objects):speak.h

.PHONY:clean
clean:
	-rm hello_demo $(objects)

