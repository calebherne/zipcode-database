LFLAGS = g++ -g -Wall 
CFLAGS = g++ -c -g -Wall
final: zipcode.o main.o database.o
	$(LFLAGS) *.o -o final
main.o: main.cpp
	$(CFLAGS) main.cpp
database.o: database.h database.cpp zipcode.h
	$(CFLAGS) database.cpp
zipcode.o: zipcode.h zipcode.cpp
	$(CFLAGS) zipcode.cpp
make run:
	./final
make clean:
	rm *.o
	rm final
make debug:
	gdb final	 
