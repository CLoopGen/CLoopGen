#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double beta;
extern double *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (lenY > 0) {
        i = 0;
        for (; i < lenY; i++) {
            for (int j = 0; j < 1; j++) {
                Y[iy] *= beta;
            }
            iy += incY;
        }
    }
}
