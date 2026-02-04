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
    for (i = 0; i < lenY && iy < lenY * incY; i++) {
        float* yPtr = (float*)Y;
        size_t index = 2 * iy;
        yPtr[index] = 0.0f;
        yPtr[index + 1] = 0.0f;
        iy += incY;
    }
}
