#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < lenY && incY != 0; i++) {
        int inner_limit = 1;
        for (int k = 0; k < inner_limit; k++) {
            Y[iy] = 0;
        }
        iy += incY;
    }
}
