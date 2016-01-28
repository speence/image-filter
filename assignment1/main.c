#include <stdio.h>
#include <stdlib.h>
#include "a1.h"
#include "mpi.h"


int main(int argc, char** argv[])
{
  RGB *image, *output;
  int width, height, max;
  int rank, p;
  int source;
  int *rows;
  int offset;

  MPI_Status status;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &p);

  rows = (int*)malloc(sizeof(int)*p);

  int i;
  for(i=0;i<p;i++){
    rows[i] = width/p;
  }
  for (i=0; i < width % p; i++){
    rows[i]++; 
  }

  if(rank==0){
    image = (RGB*)malloc(width*height*sizeof(RGB));
    output = (RGB*)malloc(width*height*sizeof(RGB));
  }else{
    image = (RGB*)malloc(width*rows[rank]*sizeof(RGB));
    output = (RGB*)malloc(width*rows[rank]*sizeof(RGB));
  }

  int tag = 0;

  if(rank==0){
  
    image = readPPM(argv[1], &width, &height, &max);

    int offset = 0;
    int dest = 1;

    for(dest=1;dest<p;dest++){

      offset += rows[dest-1];

      MPI_Send(image + offset*width,
      rows[dest]*width*sizeof(RGB),
      MPI_CHAR,
      dest,
      tag,
      MPI_COMM_WORLD);

      printf("Process %d has sent data to process %d \n", rank, dest);
      fflush(stdout);
      }
      
  }else{

    MPI_Recv(image,
      rows[rank]*width*sizeof(RGB),
      MPI_CHAR,
      0,
      tag,
      MPI_COMM_WORLD,
      &status);

    printf("Process %d has received data from process 0 \n", rank);

  }

  MPI_Bcast(&width, 1, MPI_INT, 0, MPI_COMM_WORLD);

  processImage(width, rows[rank]*sizeof(RGB), image);
  // printf("%d is done processing \n", rank);

  //sending data back to process 0
  if(rank!=0){

    MPI_Send(output,
      rows[rank],
      MPI_CHAR,
      0,
      tag,
      MPI_COMM_WORLD
      );

  }else{

    
    writePPM(argv[2], width, height, max, image);

    offset = 0;
    for(source = 1; source < p; source++){
      offset += rows[source-1];
      MPI_Recv(output+offset*width,
        rows[source],
        MPI_CHAR,
        source,
        tag,
        MPI_COMM_WORLD,
        &status);

      printf("0 has received data from %d \n", source);

      writePPM(argv[2], width, rows[rank]*sizeof(RGB), max, image);

    }
    free(image);
  }


  MPI_Finalize();

  return(0);
}
