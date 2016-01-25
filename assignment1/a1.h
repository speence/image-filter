#ifndef INCLUDED_A1_H
#define INCLUDED_A1_H

typedef struct {
  unsigned char r,g,b;
} RGB;

RGB * readPPM(char* file, int* width, int* height, int* max);
void writePPM(char* file, int width, int height, int max, const RGB *image);

void processImage(int width, int height, RGB *image);


#endif
