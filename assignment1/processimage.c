
#include "a1.h"

void processImage(int width, int height, RGB *image)
{
  // simple image "processing"
  int i;

  for (i=0; i < width*height; i++)
    {
     RGB *p = image+i;
      p->r = 150; 
	    /*printf("%d %d %d ",p->r, p->g, p->b); */
    }
}
