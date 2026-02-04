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
    // Variant 1: Strided memory access with step size 2, unrolled to process two iterations per loop cycle
    num_nz_symbols = 0;
    for (i = 0; i < 256; i += 2) {
        if (freq[i]) {
            nz_index[num_nz_symbols] = i;
            freq[num_nz_symbols] = freq[i];
            num_nz_symbols++;
        }
        if (freq[i + 1]) {
            nz_index[num_nz_symbols] = i + 1;
            freq[num_nz_symbols] = freq[i + 1];
            num_nz_symbols++;
        }
    }
    // Handle last element if necessary
    if (i == 256 && freq[256]) {
        nz_index[num_nz_symbols] = 256;
        freq[num_nz_symbols] = freq[256];
        num_nz_symbols++;
    }
}
