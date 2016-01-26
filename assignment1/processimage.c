
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
  } 
  void topLeftZero() {
    topleftred = 0;
    topleftgreen = 0;
    topleftblue = 0;
  }
  void fetchTop() {
    topred = top->r;
    topgreen = top->g;
    topblue = top->b;
  }
  void topZero() {
    topred = 0;
    topgreen = 0;
    topblue = 0;
    meandiv--;
  }
  void rightZero() {
    rightred = 0;
    rightgreen = 0;
    rightblue = 0;
  }
  void topRightZero() {
    toprightred = 0;
    toprightgreen = 0;
    toprightblue = 0;
  }
  
  for (i=0; i < width*height; i++)
    {

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
    
    
    
	if (p%(width-1) == 0){	//if we are on the right edge of the image
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

	else if (p%(width) == 0){	//if we are on the left edge of the image
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

	else if (p<(width)){	//if we are on the top edge of the image	
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

	else if (p > ((width*height)-width)){	//if we are on the bottom edge of the image
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
    }
}
