
#include "a1.h"

void processImage(int width, int height, RGB *image)
{
  // simple image "processing"
  int i;

  for (i=0; i < 20; i++)
    {
      RGB *start = image-width+i;
      RGB *p = image+i;
      //p->g = 0; 
	    printf("%d %d %d ",p->r, p->g, p->b); 
      //if (p<start) 
        //printf("Out of range");
      //else
        //printf("%d ", p->r);
        //printf("%d ", p->r);
        //printf("%d ", start);

    }
}
