#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern float *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    if (N > 0) {
        // Reduced effective loop depth by unrolling the first iteration and looping from the second
        Y[iy] *= beta;
        iy += incY;
        for (i = 1; i < N; i++) {
            Y[iy] *= beta;
            iy += incY;
        }
    }
}
