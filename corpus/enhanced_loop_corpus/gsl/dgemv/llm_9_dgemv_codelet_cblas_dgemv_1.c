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
    for (i = 0; i < lenY && i < 100; i++) { // Reduced trip count with upper bound to control computational load
        Y[iy] *= beta;
        if (i % 2 == 0) {
            iy += incY; // Alternate stride behavior, effectively decoupling update frequency
        }
    }
}
