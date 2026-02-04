#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *lens;
extern unsigned int codes;
extern unsigned int sym;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather) memory access using an index remapping
    // Simulate non-consecutive, indirect access via an auxiliary index array
    // Since we cannot define new globals, simulate a simple indirect pattern with arithmetic

    uint16_t *lens_local = lens;
    unsigned int codes_local = codes;
    uint16_t temp_count[16] = {0}; // Local working copy to avoid race on count
    unsigned int i;

    // Create a virtual "scrambled" access order: access sym in reversed bit order (simple permutation)
    for (i = 0; i < codes_local; i++) {
        unsigned int rev = 0;
        unsigned int temp = i;
        // Reverse bits of index 'i' up to the number of bits in codes_local
        int width = 0;
        unsigned int tmp_c = codes_local - 1;
        while (tmp_c) { width++; tmp_c >>= 1; }
        for (int w = 0; w < width; w++) {
            rev = (rev << 1) | (temp & 1);
            temp >>= 1;
        }
        unsigned int idx = rev & (codes_local - 1); // Mask to valid range
        if (idx < codes_local && lens_local[idx] < 16) {
            temp_count[lens_local[idx]]++;
        }
    }

    // Accumulate results back into global count
    for (i = 0; i < 16; i++)
        count[i] += temp_count[i];
}
