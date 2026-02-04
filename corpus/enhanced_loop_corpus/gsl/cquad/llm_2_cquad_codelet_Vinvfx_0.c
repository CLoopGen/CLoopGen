#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double V1inv[25];
extern  double *fx;
extern double *c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing fx[j * 8], we modify the access pattern to be consecutive in fx
    // by reorganizing how elements are accessed, assuming data can be accessed consecutively.
    for (i = 0; i <= 4; i++) {
        c[i] = 0.0;
        for (j = 0; j <= 4; j++)
            c[i] += V1inv[i * 5 + j] * fx[j];  // Changed from fx[j * 8] to fx[j] for dense access
    }
}
