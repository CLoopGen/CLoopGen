#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;
extern int k;
extern int *offt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computation to traverse offt in sequential order
    for (int idx = 0; idx < 256; idx++) {
        int j = idx >> 6;          // j = idx / 64
        int k = idx & 63;          // k = idx % 64
        offt[idx] = ((k >> 3) << 5) + ((j & 3) << 3) + (k & 7);
    }
}
