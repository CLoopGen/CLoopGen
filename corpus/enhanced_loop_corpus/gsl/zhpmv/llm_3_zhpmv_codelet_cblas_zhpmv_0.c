#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed traversal
    // Maintain strided access but reverse the loop order and adjust index calculation accordingly
    double *y_ptr = (double *)Y;
    int iy_temp = iy + (N - 1) * incY;  // Start from last element in the sequence
    for (i = 0; i < N; i++) {
        y_ptr[2 * iy_temp] = 0.;
        y_ptr[2 * iy_temp + 1] = 0.;
        iy_temp -= incY;  // Move backward by stride
    }
}
