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
for (int j = 0; j < lenY; j++) {
    for (i = 0; i <= j; i++) {
        if (i == j) {
            Y[iy] = 0.;
            iy += incY;
        }
    }
}
}
