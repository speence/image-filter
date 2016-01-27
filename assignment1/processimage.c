#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include "a1.h"

void processImage(int width, int height, RGB *image)
{
  // simple image "processing"
  int i = 0;  
  int start = image;
  int end = image+(width*height)*sizeof(RGB);

  //int numprocesses = argv[1];

  /*
  * Declaring the boxes in our 3x3 matrix 
  */

  RGB *topleft = image-width-1+i;
  RGB *top = image-width+i;
  RGB *topright = image-width+1+i;
  RGB *left = image-1+i;
  RGB *right = image+1+i;
  RGB *bottomleft = image+width-1+i;
  RGB *bottom = image+width+i;
  RGB *bottomright = image+width+1+i;  
  RGB *p = image+i;
  int current = image;
  int meandiv, meanred, meangreen, meanblue;
  
  //3x3 matrix top row variables
  int topleftred, topleftgreen, topleftblue;
  int topred, topgreen, topblue;
  int toprightred, toprightgreen, toprightblue;
  //3x3 matrix middle row variables
  int leftred, leftgreen, leftblue;
  int centrered, centregreen, centreblue;
  int rightred, rightgreen, rightblue;
  //3x3 matrix bottom row variables
  int bottomleftred, bottomleftgreen, bottomleftblue;
  int bottomred, bottomgreen, bottomblue;
  int bottomrightred, bottomrightgreen, bottomrightblue;

  /*
  * Functions that simplify the process of fetching RGB values for each pixel in our 
  * 3x3 matrix and zeroing the pixels as well
  */

  
  void fetchTopLeft() {
    topleftred = topleft->r;
    topleftgreen = topleft->g;
    topleftblue = topleft->b;
  }; 
  void topLeftZero() {
    topleftred = 0;
    topleftgreen = 0;
    topleftblue = 0;
    meandiv--;
  };
  void fetchTop() {
    topred = top->r;
    topgreen = top->g;
    topblue = top->b;
  };
  void topZero() {
    topred = 0;
    topgreen = 0;
    topblue = 0;
    meandiv--;
  };
  void fetchTopRight() {
    toprightred = topright->r;
    toprightgreen = topright->g;
    toprightblue = topright->b;
  };
  void topRightZero() {
    toprightred = 0;
    toprightgreen = 0;
    toprightblue = 0;
    meandiv--;
  };
  void fetchLeft(){
    leftred = left->r;
    leftgreen = left->g;
    leftblue = left->b;
  };
  void leftZero() {
    leftred = 0;
    leftgreen = 0;
    leftblue = 0;
    meandiv--;
  }
  void fetchRight() {
    rightred = right->r;
    rightgreen = right->g;
    rightblue = right->b;
  }
  void rightZero() {
    rightred = 0;
    rightgreen = 0;
    rightblue = 0;
    meandiv--;
  };
  void fetchBottomLeft() {
    bottomleftred = bottomleft->r;
    bottomleftgreen = bottomleft->g;
    bottomleftblue = bottomleft->b;
  };
  void bottomLeftZero() {
    bottomleftred = 0;
    bottomleftgreen = 0;
    bottomleftblue = 0;
    meandiv--;
  };
  void fetchBottom() {
    bottomred = bottom->r;
    bottomgreen = bottom->g;
    bottomblue = bottom->b;
  };
  void bottomZero() {
    bottomred = 0;
    bottomgreen = 0;
    bottomblue = 0;
    meandiv--;
  };
  void fetchBottomRight() {
    bottomrightred = bottomright->r;
    bottomrightgreen = bottomright->g;
    bottomrightblue = bottomright->b;
  };
  void bottomRightZero() {
    bottomrightred = 0;
    bottomrightgreen = 0;
    bottomrightblue = 0;
    meandiv--;
  };
  void fetchCentre(){
    centrered = p->r;
    centregreen = p->g;
    centreblue = p->b;
  };

  /*
  int k = 0;
  for (k=0; k < width*height; k++)
    {
    fetchCentre();  //pull our centre pixel's RGB values
    meandiv = 9;
    if (current%(width-1) == 0){	//if we are on the right edge of the image
      rightZero();
      if(top<start){	//if we are on the top right corner of the image
        topRightZero();
      }
      else{
        fetchTopRight();
      }	
      if(bottom>end){	//if we are ont he bottom right corner of the image
        bottomRightZero();
      }
      else{
        fetchBottomRight();
      }		
    }

    else if (current%(width) == 0){	//if we are on the left edge of the image
      leftZero();
      if(top<start){	//if we are on the top left corner of the image
        topLeftZero();
      }
      else{
        fetchTopLeft();
      }		
      if(bottom>end){	//if we are on the bottom left corner of the image
        bottomLeftZero();
      }
      else{
        fetchBottomLeft();
      }	
    }

    else if (current<(width)){	//if we are on the top edge of the image	
      topZero();
      if(topleft<start){	//if we are on the top left corner of image
        topLeftZero();
      }
      else{
        fetchTopLeft();
      }
      if(topright<start){	//if we are on the top right corner of image 
        topRightZero();
      }
      else{
        fetchTopRight();
      }
    }

    else if (current > ((width*height)-width)){	//if we are on the bottom edge of the image
      bottomZero();
      if(bottomright>end){	//if we are on the bottom right corner of image
        bottomRightZero();
      }
      else{
        fetchBottomRight();
      }
      if(bottomleft>end){	//if we are on the bottom left corner of image
        bottomLeftZero();
      }
      else{
        fetchBottomLeft();
      }
    }
    
    //calculating means
    meanred = ((topleftred+topred+toprightred+leftred+centrered+rightred+bottomleftred+bottomred+bottomrightred)/meandiv);
    meangreen = ((topleftgreen+topgreen+toprightgreen+leftgreen+centregreen+rightgreen+bottomleftgreen+bottomgreen+bottomrightgreen)/meandiv);
    meanblue = ((topleftblue+topblue+toprightblue+leftblue+centreblue+rightblue+bottomleftblue+bottomblue+bottomrightblue)/meandiv);
    
    //incrementing values for the next iteration
    topright = topright + k;  
    top = top + k;
    topleft = topleft + k;
    left = left+k;
    right = right + k;
    bottomleft = bottomleft + k;
    bottom = bottom + k;
    bottomright = bottomright + k;
    p = p + k;
    current = current + k*sizeof(RGB);
  }
  
  //should be the same
  printf("%d\n", p->r);
  printf("%d\n", topleftred);
  */
}
