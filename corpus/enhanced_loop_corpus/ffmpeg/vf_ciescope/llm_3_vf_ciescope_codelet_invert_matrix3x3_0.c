#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double out[3][3];
extern int i;
extern int j;
extern double det;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use strided linear access via pointer arithmetic to traverse the 3x3 matrix as a flat array with stride
    double *p = &out[0][0];
    int stride = 1; // Access every element consecutively (linearized)
    for (int idx = 0; idx < 9; idx += stride) {
        p[idx] *= det;
    }
}
