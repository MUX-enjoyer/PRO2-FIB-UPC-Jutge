OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: main.o CjtMensajes.o CjtAlfabetos.o Alfabeto.o Mensaje.o
	g++ -o program.exe main.o CjtMensajes.o CjtAlfabetos.o Alfabeto.o Mensaje.o

main.o: main.cc CjtMensajes.hh CjtAlfabetos.hh Mensaje.hh Alfabeto.hh BinTree.hh
	g++ -c main.cc $(OPCIONS)

Alfabeto.o: Alfabeto.cc Alfabeto.hh
	g++ -c Alfabeto.cc $(OPCIONS)

CjtAlfabetos.o: CjtAlfabetos.cc CjtAlfabetos.hh Alfabeto.hh
	g++ -c CjtAlfabetos.cc $(OPCIONS)

Mensaje.o: Mensaje.cc Mensaje.hh CjtAlfabetos.hh Alfabeto.hh BinTree.hh
	g++ -c Mensaje.cc $(OPCIONS)

CjtMensajes.o: CjtMensajes.cc CjtMensajes.hh Mensaje.hh CjtAlfabetos.hh Alfabeto.hh BinTree.hh
	g++ -c CjtMensajes.cc $(OPCIONS)

entrega:
	tar -cvf practica.tar Makefile *.cc *.hh

clean:
	rm -f *.o *.exe *.tar
