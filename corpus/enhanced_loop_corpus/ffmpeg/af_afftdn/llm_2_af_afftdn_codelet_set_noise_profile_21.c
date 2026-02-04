#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double temp[15];
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step of 2, then handle odd indices if needed)
    // We'll traverse with stride 2, then clean up any remaining elements.
    sum = 0.0;
    int m;
    for (m = 0; m < 15; m += 2) {
        sum += temp[m];
    }
    for (m = 1; m < 15; m += 2) {
        sum += temp[m];
    }
}
