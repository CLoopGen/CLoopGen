#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *_usr_index;
extern int k;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Strided memory access with stride of 2, starting from k=4
    for (int stride_k = 0; stride_k < 2; stride_k++) {
        int k = 4 + stride_k * 2;  // Access index[4] and index[6]
        if (k < 6) continue;       // Skip if k >= 6 to maintain original bounds
        if (index[k] >= 44 && index[k] < 108) {
            index[k] += 64;
        } else if (index[k] >= 108 && index[k] < 128) {
            index[k] += 128;
        }
    }
}
