#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double temp[15];
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    int order[15];
    for (int i = 0; i < 15; i++) {
        order[i] = (7 + i * 11) % 15;  // Generate a pseudo-random permutation using linear congruential map
    }
    sum = 0.0;
    for (int m = 0; m < 15; m++) {
        sum += temp[order[m]];
    }
}
