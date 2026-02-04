#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int k;
extern int xbit[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Precompute access order using an index mapping (e.g., bit-reversed order)
    int idx_map[31];
    for (k = 0; k < 31; ++k) {
        int reversed = 0;
        int temp = k;
        for (int b = 0; b < 5; ++b) { // 5 bits to cover indices 0-30
            reversed = (reversed << 1) | (temp & 1);
            temp >>= 1;
        }
        idx_map[k] = reversed < 31 ? reversed : k; // map out-of-range back to original
    }

    int temp_val[31];
    for (k = 0; k < 31; ++k) {
        temp_val[k] = i % 2;
        i /= 2;
    }

    // Write values using indirect addressing
    for (k = 0; k < 31; ++k) {
        xbit[idx_map[k]] = temp_val[k];
    }
}
