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
        float* ptr = (float*)Y;
        ptr[2 * iy] = 0.0f;
        if (i % 2 == 0) {
            ptr[2 * iy + 1] = 0.0f;
        }
        iy += incY;
    }
}
