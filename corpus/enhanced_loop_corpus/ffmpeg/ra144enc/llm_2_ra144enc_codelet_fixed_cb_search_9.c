#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int8_t ff_cb1_vects[128][40];
extern int *cb1_idx;
extern int i;
extern float vect[40];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Access pattern: i = 0, 2, 4, ..., 38 and then handle odd indices if needed
    // Here we split into two loops for even and odd to maintain all 40 elements
    int j;
    for (j = 0; j < 40; j += 2) {
        vect[j] = ff_cb1_vects[*cb1_idx][j];
    }
    for (j = 1; j < 40; j += 2) {
        vect[j] = ff_cb1_vects[*cb1_idx][j];
    }
}
