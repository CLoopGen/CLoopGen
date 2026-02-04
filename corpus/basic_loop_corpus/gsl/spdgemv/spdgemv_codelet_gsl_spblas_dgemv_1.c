#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double beta;
extern size_t j;
extern size_t incY;
extern size_t lenY;
extern double *Y;
extern size_t jy;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 0; j < lenY; ++j) {
    Y[jy] *= beta;
    jy += incY;
}

}
