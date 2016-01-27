#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include "a1.h"

void processImage(int width, int height, RGB *image) { 
  int k;
  int N = 5;
  RGB* window[N*N];
  int i;
  int j;
  int h;
  for (k=0; k < width*height; k++) {
    RGB* p = image + k;
    int windowrow = -(N/2);
    for (i=0; i < N*N; i=i+N){
      for (j=0; j < N; j++) {
        window[i+j] = image + k + (width*windowrow*sizeof(RGB)) - (N/2) + j;
      }
      windowrow++;
    }
  }
      for (h=0; h<N*N; h++){
      printf("%d\n", window[h]);
    }printf("%d %d\n", window[5]-window[0],window[10]-window[5]);  

}
             
             
