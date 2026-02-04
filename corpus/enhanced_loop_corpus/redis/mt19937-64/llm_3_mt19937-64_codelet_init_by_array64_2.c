#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long mt[312];
extern unsigned long long i;
extern unsigned long long k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather-style) access using an index map
    unsigned long long indices[312];
    for (int j = 0; j < 312; j++) {
        indices[j] = (311 - j); // Reverse order access pattern
    }
    for (k = 312 - 1; k; k--) {
        int curr_idx = indices[i];
        int prev_idx = indices[(i - 1 + 312) % 312];
        mt[curr_idx] = (mt[curr_idx] ^ ((mt[prev_idx] ^ (mt[prev_idx] >> 62)) * 2862933555777941757ULL)) - i;
        i++;
        if (i >= 312) {
            mt[indices[0]] = mt[indices[311]];
            i = 1;
        }
    }
}
