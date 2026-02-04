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
    for (j = 0; j < lenY; ++j) {
        Y[jy] = 0.;
        if (incY > 1) {
            jy += incY - 1;
        }
        jy += 1;
    }
}
