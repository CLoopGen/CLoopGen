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
    // Variant 1: Strided memory access pattern
    // Access fx with a fixed stride of 3 (wrapping within bounds using modulo)
    for (i = 0; i <= 32; i++) {
        c[i] = 0.0;
        for (j = 0; j <= 32; j++) {
            int idx = (j * 3) % 33;  // Strided access: every third element, wrap-around
            c[i] += V4inv[i * 33 + j] * fx[idx];
        }
    }
}
