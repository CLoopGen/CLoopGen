#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = 0.;
    for (i = 0; i < N; i++) {
        Y[iy] = temp;
        temp = Y[iy]; // Introduce RAW (read after write) and loop-carried dependency via temp
        iy += incY;
    }
}
