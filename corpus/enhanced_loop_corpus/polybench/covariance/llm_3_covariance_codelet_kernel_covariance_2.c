#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double data[1400][1200];
extern double mean[1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (linearized) memory access using pointer arithmetic
    double *d = &data[0][0];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            *(d + i * 1200 + j) -= mean[j]; // Ensures row-major consecutive access pattern
        }
    }
}
