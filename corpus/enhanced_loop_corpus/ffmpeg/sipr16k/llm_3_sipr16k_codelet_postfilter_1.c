#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const float ff_pow_0_5[16];
extern float *iir_mem;
extern float *filt_mem[2];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating non-sequential access)
    const int index_map[16] = {0, 2, 4, 6, 8, 10, 12, 14, 1, 3, 5, 7, 9, 11, 13, 15}; // Even indices followed by odd
    for (i = 0; i < 16; i++) {
        int idx = index_map[i];
        filt_mem[0][idx] = iir_mem[idx] * ff_pow_0_5[idx];
    }
}
