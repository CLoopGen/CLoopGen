#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long freq[];
extern int nz_index[257];
extern int i;
extern int num_nz_symbols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop and redundant arithmetic
    num_nz_symbols = 0;
    for (i = 0; i < 257; i += 4) {
        // Process 4 iterations per loop trip with explicit unrolling
        if (i + 0 < 257 && freq[i + 0]) {
            nz_index[num_nz_symbols] = i + 0;
            long temp = freq[i + 0];
            freq[num_nz_symbols] = temp * temp + temp; // Extra arithmetic: f^2 + f
            num_nz_symbols++;
        }
        if (i + 1 < 257 && freq[i + 1]) {
            nz_index[num_nz_symbols] = i + 1;
            long temp = freq[i + 1];
            freq[num_nz_symbols] = temp * temp + temp;
            num_nz_symbols++;
        }
        if (i + 2 < 257 && freq[i + 2]) {
            nz_index[num_nz_symbols] = i + 2;
            long temp = freq[i + 2];
            freq[num_nz_symbols] = temp * temp + temp;
            num_nz_symbols++;
        }
        if (i + 3 < 257 && freq[i + 3]) {
            nz_index[num_nz_symbols] = i + 3;
            long temp = freq[i + 3];
            freq[num_nz_symbols] = temp * temp + temp;
            num_nz_symbols++;
        }
    }
}
