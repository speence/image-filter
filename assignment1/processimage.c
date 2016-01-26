
#include "a1.h"

void processImage(int width, int height, RGB *image)
{
  // simple image "processing"
  int i = 0;  
  RGB *start = image;
  RGB *end = image+(width*height);
  RGB *topleft = image-width-1+i;
  RGB *top = image-width+i;
  RGB *topright = image-width+1+i;
  RGB *left = image-1+i;
  RGB *right = image+1+i;
  RGB *bottomleft = image+width-1+i;
  RGB *bottom = image+width+i;
  RGB *bottomright = image+width+1+i;  
  RGB *p = image+i;
  int meandiv = 9;
  int mean;

  //top window variables
  int topleftred, topleftgreen, topleftblue;
  int topred, topgreen, topblue;
  int toprightred, toprightgreen, toprightblue;
  //middle window variables
  int leftred, leftgreen, leftblue;
  int rightred, rightgreen, rightblue;
  //bottom window variables
  int bottomleftred, bottomleftgreen, bottomleftblue;
  int bottomred, bottomgreen, bottomblue;
  int bottomrightred, bottomrightgreen, bottomrightblue;
  
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
    bottomrightred = 0;
    bottomrightgreen = 0;
    bottomrightblue = 0;
  };
  void BottomRightZero() {
    bottomrightred = 0;
    bottomrightgreen = 0;
    bottomrightblue = 0;
  };
  void test() {
    printf("Testing this function");
  }
  for (i=0; i < 10; i++)
    {
      test();
      /*top left window logic */
      if (topleft<start) { 
        topleftred = 0;
        topleftgreen = 0;
        topleftblue = 0;
        meandiv--;
        //printf("topleft didn't run ");
      }else {
        topleftred = topleft->r;
        topleftgreen = topleft->g;
        topleftblue = topleft->b;
        //printf("topleft ran ");
      }
    /*top window logic */
      if (top<start) { 
        topred = 0;
        topgreen = 0;
        topblue = 0;
        meandiv--;
      }else {
        topred = top->r;
        topgreen = top->g;
        topblue = top->b;
      }
      /*top right window logic */
      if (topright<start) { 
        toprightred = 0;
        toprightgreen = 0;
        toprightblue = 0;
        meandiv--;
      }else {
        toprightred = topright->r;
        toprightgreen = topright->g;
        toprightblue = topright->b;
      }
      /*left window logic */
      if (left<start) { 
        leftred = 0;
        leftgreen = 0;
        leftblue = 0;
        meandiv--;
      }else {
        leftred = left->r;
        leftgreen = left->g;
        leftblue = left->b;
      }
      /*right window logic */
      if (topright<start) { 
        toprightred = 0;
        toprightgreen = 0;
        toprightblue = 0;
        meandiv--;
      }else {
        toprightred = topright->r;
        toprightgreen = topright->g;
        toprightblue = topright->b;
      }
    
    
    
     if (p%(width-1) == 0){ //if on the right edge of image


        bottomrightred = 0;
        bottomrightgreen = 0;
        bottomrightblue = 0;
        meandiv = meandiv - 3;
        if (top<start){ //if in the top right corner
          topred = 0;
          topgreen = 0;
          topblue = 0;
          meandiv--;
        }else {
          topred = top->r;
          topgreen = top->g;
          topblue = top->b;
        }
        if (bottom>end){ //if in bottom right corner
          bottomred = 0;
          bottomgreen = 0;
          bottomblue = 0;
          meandiv--;
        }else {
          bottomred = bottom->r;
          bottomgreen = bottom->g;
          bottomblue = bottom->b;
        }
    }
  }
}
