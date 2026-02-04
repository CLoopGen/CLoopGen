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
    size_t i, block_size = 16;
    for (i = 0; i < lenY; i += block_size) {
        for (j = i; j < lenY && j < i + block_size; ++j) {
            Y[jy] = 0.;
            jy += incY;
        }
    }
}
