all: ppmf

ppmf: main.c readwriteppm.c processimage.c
	mpicc -o ppmf main.c readwriteppm.c processimage.c

clean:
	rm ppmf output.* *.o 

