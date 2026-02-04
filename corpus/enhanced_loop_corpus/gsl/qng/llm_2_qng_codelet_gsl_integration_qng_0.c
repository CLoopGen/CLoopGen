#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double w43a[10];
extern double savfun[21];
extern double res43;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Access pattern: k = 0, 2, 4, 6, 8 (even indices only)
    res43 = 0.0;
    for (k = 0; k < 10; k += 2) {
        res43 += savfun[k] * w43a[k];
    }
}
