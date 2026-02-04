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
    int outer_i;
    int chunk = 1;
    for (outer_i = 0; outer_i < lenY; outer_i += chunk) {
        int i;
        for (i = outer_i; i < lenY && i < outer_i + chunk; i++) {
            Y[iy] *= beta;
            iy += incY;
        }
    }
}
