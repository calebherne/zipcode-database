LFLAGS = g++ -g -Wall
CFLAGS = g++ -c -g -Wall
final: zipcode.o main.o
	$(LFLAGS) *.o -o final
testobj.o: zipcode.h zipcode.cpp
	$(CFLAGS) zipcode.cpp
main.o: main.cpp
	$(CFLAGS) main.cpp
make run:
	./final
make clean:
	rm *.o
	rm final
make debug:
	gdb final	 
