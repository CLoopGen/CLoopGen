#include <stdio.h>

#include <inttypes.h>

extern long x;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via index remapping (bit-reversal permutation simulation)
    // Access bits in a non-consecutive, indirect order using a precomputed index map
    n = 0;
    int bit_width = sizeof(long) * 8;
    for (i = 0; i < bit_width; ++i) {
        int rev_i = 0;
        for (int b = 0; b < bit_width; ++b) {
            if ((1 << b) & i) {
                rev_i |= 1 << ((bit_width - 1) - b);
            }
        }
        // Access bit at reversed position, clamp to valid range
        int bit_pos = rev_i % bit_width;
        n += (int)((x >> bit_pos) & 1L);
    }
}
