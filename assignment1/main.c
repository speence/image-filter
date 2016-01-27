#include <stdio.h>
#include <stdlib.h>
#include "a1.h"
#include "mpi.h"


int main(int argc, char** argv[])
{
  RGB *image;
  int width, height, max;
  int rank, size;
  int rows;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if(rank==0){
    printf("Process %d is reading the image.\n", rank);
    image = readPPM(argv[1], &width, &height, &max);

    rows = (height/size);

    printf("Number of rows sent to each process is %d \n", rows);

    printf("Process %d is processing the image.\n", rank);
    processImage(width, height, image);
    printf("Process %d is writing to the image.\n", rank);
    writePPM(argv[2], width, height, max, image);
    printf("Process %d is freeing the image.\n", rank);
    free(image); 
  }

  printf("Hello world, I am %d of %d \n", rank, size);

  MPI_Finalize();

  return(0);
}
