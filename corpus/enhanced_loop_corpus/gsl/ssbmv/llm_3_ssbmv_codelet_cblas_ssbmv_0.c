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
    // Variant 2: Strided access with reversed iteration order (backward traversal)
    int iy_temp = iy + (N - 1) * incY;
    for (i = 0; i < N; i++) {
        Y[iy_temp] = 0.0f;
        iy_temp -= incY;
    }
}
