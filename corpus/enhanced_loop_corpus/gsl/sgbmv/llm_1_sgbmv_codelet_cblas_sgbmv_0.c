#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (lenY > 0) {
    i = 0;
    do {
        Y[iy] = 0;
        iy += incY;
        i++;
    } while (i < lenY);
}
}
