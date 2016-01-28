#include <stdio.h>
#include <stdlib.h>
#include "a1.h"
#include "mpi.h"


int main(int argc, char** argv[])
{
  RGB *image, *output;
  int width, height, max;
  int rank, p;
  int source,dest;
  int *rows;
  int offset;
  int tag = 0;
  MPI_Status status;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &p);

  rows = (int*)malloc(sizeof(int)*p);
  if(rank==0){
    image = (RGB*)malloc(width*height*sizeof(RGB));
  }else{
    image = (RGB*)malloc(width*rows[rank]*sizeof(RGB));
  }
  int i;
  for(i=0;i<p;i++){
    rows[i] = height/p;
  }
  for (i=0; i < height % p; i++){
    rows[i]++; 
  }

  if(rank==0){
  
    image = readPPM(argv[1], &width, &height, &max);

    offset = 0;
    dest = 1;

    for(dest=1;dest<p;dest++){

      offset += rows[dest-1];

      MPI_Send(image + offset*width,
      rows[dest]*width*sizeof(RGB),
      MPI_CHAR,
      dest,
      tag,
      MPI_COMM_WORLD);

      }
      
  }else{

    MPI_Recv(image,
      rows[rank]*width*sizeof(RGB),
      MPI_CHAR,
      0,
      tag,
      MPI_COMM_WORLD,
      &status);

  }

  MPI_Bcast(&width, 1, MPI_INT, 0, MPI_COMM_WORLD);

  //sending data back to process 0
  if(rank!=0){
    processImage(width, rows[rank], image);
    
    MPI_Send(output,
      rows[rank]*width*sizeof(RGB),
      MPI_CHAR,
      0,
      tag,
      MPI_COMM_WORLD
      );

  }else{

    processImage(width, rows[rank], image);

    writePPM(argv[2], width, height, max, image);

    offset = 0;
    for(source = 1; source < p; source++){
      offset += rows[source-1];
      MPI_Recv(image+offset*width,
        rows[source]*width*sizeof(RGB),
        MPI_CHAR,
        source,
        tag,
        MPI_COMM_WORLD,
        &status);

      writePPM(argv[2], width, height, max, image);
    }
    free(image);
  }

  free(rows);
  MPI_Finalize();

  return(0);
}
