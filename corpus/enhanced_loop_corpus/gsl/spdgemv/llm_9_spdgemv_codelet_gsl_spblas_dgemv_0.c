#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t j;
extern size_t incY;
extern size_t lenY;
extern double *Y;
extern size_t jy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < lenY * 2; j += 2) {
        Y[jy] = 0.;
        if (j + 1 < lenY * 2) {
            Y[jy + incY] = 0.;
        }
        jy += incY;
    }
}
