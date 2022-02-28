ALL: main

main: main.o listaencadeada.o
	gcc main.o listaencadeada.o -o main

main.o: main.c listaencadeada.h
	gcc -c main.c

listaencadeada.o: listaencadeada.c listaencadeada.h
	gcc -c listaencadeada.c

clean:
	rm -f *.o main