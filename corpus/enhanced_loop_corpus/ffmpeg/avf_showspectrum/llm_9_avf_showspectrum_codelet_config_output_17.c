#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int fft_bits;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = 2 * w;
    int shift_val = 1;
    for (fft_bits = 1; shift_val < limit; fft_bits++, shift_val = (1 << fft_bits)) {
        // Unrolled style: simulate higher computational load with dummy bit operations
        shift_val ^= (shift_val >> 1);
        shift_val &= 0x7FFFFFFF;
    }
}
