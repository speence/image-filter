
#include "a1.h"

void processImage(int width, int height, RGB *image)
{ 
  // simple image "processing"
  int i = 0;  
  int start = image;
  int end = start+width*height*sizeof(RGB);
  //RGB *topleft = (RGB*)malloc(width*height*sizeof(RGB));
  RGB *topleft = image-width-1;
  RGB *top = image-width+i;
  RGB *topright = image-width+1+i;
  RGB *left = image-1+i;
  RGB *right = image+1+i;
  RGB *bottomleft = image+width-1+i;
  RGB *bottom = image+width+i;
  RGB *bottomright = image+width+1+i;  
  RGB *p = image;
  int current = image;
  int meandiv;
  
  //top window variables
  RGB *topleftred, *topleftgreen, *topleftblue;
  RGB *topred, *topgreen, *topblue;
  RGB *toprightred, *toprightgreen, *toprightblue;
  //middle window variables
  RGB *leftred, *leftgreen, *leftblue;
  RGB *rightred, *rightgreen, *rightblue;
  //bottom window variables
  RGB *bottomleftred, *bottomleftgreen, *bottomleftblue;
  RGB *bottomred, *bottomgreen, *bottomblue;
  RGB *bottomrightred, *bottomrightgreen, *bottomrightblue;
  
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
  int k = 0;
  for (k=10*width; k <= 10*width+10; k++)
    {
    topleft = image-width-1+k;
    top = image-width+k;
    topright = image-width+1+k;
    left = image-1+k;
    right = image+1+k;
    bottomleft = image+width-1+k;
    bottom = image+width+k;
    bottomright = image+width+1+k;  
    p = image + k;
    current = image + sizeof(RGB)*k/sizeof(int);
    meandiv = 9;
    fetchTop();
    fetchTopRight();
    printf("%d %d\n", top->r, topred);
    if (top->r==topred)
      printf("true\n");
    p->r = topred+ toprightred;
    /*
    //printf("%d %d\n", p, current);
    if (k%(width-1) == 0){	//if we are on the right edge of the image
      rightZero();
      topRightZero();
      bottomRightZero();
      fetchLeft();
      if(k==(width-1)){	//if we are on the top right corner of the image
        topZero();
        topLeftZero();
        fetchBottomLeft();
        fetchBottom();
      }
      else if(k==(width*height-1)){//if we are on the bottom right corner of the image
        bottomZero();
        bottomLeftZero();
        fetchTop();
        fetchTopLeft();
      }
      else{ //on the right edge but not on the corners
        fetchBottom();
        fetchBottomLeft();
        fetchTopLeft();
        fetchTop();
      }		
    }

    else if (k%width == 0){	//if we are on the left edge of the image
      leftZero();
      topLeftZero();
      bottomLeftZero();
      fetchRight();
      if(k == 0){	//if we are on the top left corner of the image
        topZero();
        topRightZero();
        fetchBottom();
        fetchBottomRight();
      }	
      else if(k == (width*height-width-1)){	//if we are on the bottom left corner of the image
        bottomZero();
        bottomRightZero();
        fetchTop();
        fetchTopRight();
      }
      else{ //left edge of image but not in the corners
        fetchBottomRight();
        fetchTopRight();
        fetchTop();
        fetchBottom();
      }	
    }

    else if (k<width){	//if we are on the top edge of the image	
      topZero();
      topLeftZero();
      topRightZero();
      fetchBottom();
      if(k == 0){	//if we are on the top left corner of image
        leftZero();
        bottomLeftZero();
        fetchRight();
        fetchBottomRight();
      }
      else if(k == (width-1)){	//if we are on the top right corner of image 
        rightZero();
        bottomRightZero();
        fetchBottomLeft();
        fetchLeft();
      }
      else{ //if we are on the top row not on the corners
        fetchRight();
        fetchLeft();
        fetchBottomLeft();
        fetchBottomRight();
      }
    }

    else if (k>=((width*height-width-1))){	//if we are on the bottom edge of the image
      bottomZero();
      bottomLeftZero();
      bottomRightZero();
      fetchTop();
      if(k == (width*height-1)){	//if we are on the bottom right corner of image
        rightZero();
        topRightZero();
        fetchLeft();
        fetchTopLeft();
      }
      else if(k == (width*height-width-1)){	//if we are on the bottom left corner of image
        leftZero();
        topLeftZero();
        fetchTopRight();
        fetchRight();
      }
      else{ //if we are on the bottom row but not the corners
        fetchLeft();
        fetchRight();
        fetchTopLeft();
        fetchTopRight();
      }
    }*/
    //calculating means
    //p->r=((topleftred+topred+toprightred+leftred+rightred+bottomleftred+bottomred+bottomrightred)/meandiv);
    //p->g = ((topleftgreen+topgreen+toprightgreen+leftgreen+(p->g)+rightgreen+bottomleftgreen+bottomgreen+bottomrightgreen)/meandiv);
    //p->b = ((topleftblue+topblue+toprightblue+leftblue+(p->b)+rightblue+bottomleftblue+bottomblue+bottomrightblue)/meandiv);
    //int x = atoi(topred);
    
    //bottomZero();
    //topLeftZero();
    //printf("%d %d\n", p->r, topleftred->r);
    //p->r=topleftred;
    //printf("%d %d\n", p, topleft);
    //int d = p - topleft;
    //printf("%d\n", d);
    /*
    topright = topright + k;
    top = top + k;
    topleft = topleft + k;
    left = left+k;
    right = right + k;
    bottomleft = bottomleft + k;
    bottom = bottom + k;
    bottomright = bottomright + k;
    p = p + k;
    current = current + k*sizeof(RGB);*/
  }
  //should be the same
  /*printf("%d\n", start+width*height*sizeof(RGB));
  printf("%d\n", current);
  printf("%d %d\n", p, end);
  printf("Difference between p and end %d\n", p-end);
  printf("size of int:%d size of RGB:%d\n", sizeof(int), sizeof(RGB));*/
}
             
             
