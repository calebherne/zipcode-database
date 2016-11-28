LFLAGS = g++ -g -Wall
CFLAGS = g++ -c -g -Wall
final:testobj.o main.o
	$(LFLAGS) *.o -o final
testobj.o: testobj.h testobj.cpp
	$(CFLAGS) testobj.cpp
main.o: main.cpp
	$(CFLAGS) main.cpp
make run:
	./final
make clean:
	rm *.o
make debug:
	gdb final	 
