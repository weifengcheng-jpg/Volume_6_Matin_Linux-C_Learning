hello_demo : hellospeak.o speak.o
	gcc -o hello_demo hellospeak.o speak.o

hellospeak.o : hellospeak.c speak.h
	gcc -c hellospeak.c

speak.o : speak.c  speak.h
	gcc -c speak.c

clean :
	rm hello_demo speak.o hellospeak.o


