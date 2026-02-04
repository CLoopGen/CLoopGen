#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long mt[312];
extern unsigned long long i;
extern unsigned long long k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (forward wrapping)
    for (k = 312 - 1; k; k--) {
        int stride = 2;
        int idx = i % 312;
        int prev_idx = (i - 1 + 312) % 312;
        mt[idx] = (mt[idx] ^ ((mt[prev_idx] ^ (mt[prev_idx] >> 62)) * 2862933555777941757ULL)) - i;
        i += stride;
        if (i >= 312) {
            i = (i == 312) ? 0 : 1; // Adjust to maintain valid index after striding
            mt[0] = mt[311];
        }
    }
}
