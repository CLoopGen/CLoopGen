#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double V4inv[1089];
extern  double *fx;
extern double *c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (reverse-ordered) memory access pattern
    // Reverse the inner loop to access fx and V4inv in descending consecutive order
    // This improves spatial locality in some cache architectures
    for (i = 0; i <= 32; i++) {
        c[i] = 0.0;
        for (j = 32; j >= 0; j--) {
            c[i] += V4inv[i * 33 + j] * fx[j];  // Still consecutive but accessed backward
        }
    }
}
