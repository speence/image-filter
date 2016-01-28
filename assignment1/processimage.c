#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include "a1.h"

void processImage(int width, int height, RGB *image) { 
  int k;
  int N = 3;
  RGB *window[N*N];
  RGB *zero = (RGB*)malloc(sizeof(RGB));
  zero->r = 0;
  zero->g = 0;
  zero->b = 0;
  int i;
  int j;
  int h;
  int u;

  for (k=0; k < width*height; k++) { //iterates over each pixel
    RGB *p = image + k;
    int windowrow = -(N/2);
    int meandiv = N*N;
    int redmean = 0;
    for (i=0; i < N*N; i=i+N){ //constructs NxN filter window
      for (j=0; j < N; j++) {
        window[i+j]= (image + k + (width*windowrow*sizeof(RGB)) - (N/2) + j);
      }
      windowrow++;
    }
    if (k%width == 0){	//if we are on the left edge of the image
      for (u=0; u < N*N; u=u+N) {
        window[u] = zero;        
      }
      meandiv = meandiv-N;
      if (k == 0){ //if we are in the top left corner
        for (u=0; u < N; u++) {
          window[u] = zero;
        }        
       meandiv = meandiv-N+1;
      }else if (k == (width*height-width-1)){ //bottom left corner
        for (u=N*N-N; u<N*N; u++){
          window[u] = zero;
        }        
        meandiv = meandiv-N+1;
      }
    }
    else if (k%(width-1) == 0){	//if we are on the right edge of the image
      for (u=N-1; u < N*N; u=u+N) {
        window[u] = zero;
      }
      meandiv = meandiv-N;
      if (k == 0){ //if we are in the top right corner
        for (u=0; u < N; u++) {
          window[u] = zero;
        }
        meandiv = meandiv-N+1;
      }else if (k == (width*height-width-1)){ //bottom right corner
        for (u=N*N-N; u<N*N; u++){
          window[u] = zero;     
        }
        meandiv = meandiv-N+1;
      }
    }
    else if (k<width){	//if we are on the top edge of the image
      for (u=0; u < N; u++) {
        window[u] = zero;
      }
      meandiv = meandiv-N;
      if (k == 0){ //if we are in the top left corner
        for (u=0; u < N*N; u=u+N) {
          window[u] = zero;
        }
        meandiv = meandiv-N+1;
      }else if (k == (width*height-width-1)){ //top right corner
        for (u=N-1; u<N*N; u=u+N){
          window[u] = zero;       
        }
        meandiv = meandiv-N+1;
      }
    }
    else if (k>=(width*height - width)){ //bottom row
      for (u=N*N-N; u < N*N; u++) {
        window[u] = zero;
      }
      meandiv = meandiv-N;
      if (k == 0){ //if we are in the bottom left corner
        for (u=0; u < N*N; u=u+N) {
          window[u] = zero;
        }
        meandiv = meandiv-N+1;
      }else if (k == (width*height-width-1)){ //bottom right corner
        for (u=N-1; u<N*N; u=u+N){
          window[u] = zero;      
        }
        meandiv = meandiv-N+1;
      }     
    }
    //for (h=0; h < N*N; h++){
      //redmean = (window[1]->r)+(window[2]->r);
    //}
  }
      for (h=0; h < N*N; h++){
        //window[h] = zero;
        //printf("%d\n", window[2]->r+window[3]->r);
        //fflush(stdout);
      }//printf("%d %d\n", window[7]-window[0],window[14]-window[7]);

}
             
             
