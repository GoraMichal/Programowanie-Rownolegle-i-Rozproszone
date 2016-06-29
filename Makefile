# kompilator c
CCOMP = mpicc

# konsolidator
LINK = mpicc

MPIRUN = /usr/lib64/openmpi/bin/mpiexec 

# opcje optymalizacji:
# wersja do debugowania
# OPT = -g -DDEBUG -p
# wersja zoptymalizowana do mierzenia czasu
# OPT = -O3 -fopenmp -p

# pliki naglowkowe
#INC = -I../pomiar_czasu

# biblioteki
#LIB = -L../pomiar_czasu -lm
LIB = -lm

# zaleznosci i komendy

heat: heat.o
	$(LINK) $(OPT) heat.o -o heat $(LIB)

heat.o: heat.c
	$(CCOMP) -c $(OPT) heat.c $(INC)

run:
	$(MPIRUN) -np 8 ./heat

clean:
	rm -f *.o
