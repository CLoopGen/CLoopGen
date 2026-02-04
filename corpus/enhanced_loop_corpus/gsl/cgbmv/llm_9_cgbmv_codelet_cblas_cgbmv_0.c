#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenY; i++) {
    int baseIdx = 2 * iy;
    float *yPtr = (float *)Y;
    yPtr[baseIdx] = (float)(0.0);
    yPtr[baseIdx + 1] = (float)(0.0);
    yPtr[baseIdx + 2] = (float)(0.0);
    yPtr[baseIdx + 3] = (float)(0.0);
    iy += incY;
}
}
