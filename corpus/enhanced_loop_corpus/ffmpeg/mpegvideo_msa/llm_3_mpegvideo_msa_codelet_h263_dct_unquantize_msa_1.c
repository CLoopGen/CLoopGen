#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int16_t qmul;
extern int16_t qadd;
extern int8_t n_coeffs;
extern int32_t level;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index map (simulated via arithmetic)
    // Simulate indirect access by reversing the traversal order (reverse mapping)
    for (int32_t rev_idx = 0; rev_idx <= n_coeffs; rev_idx++) {
        int32_t actual_idx = n_coeffs - rev_idx;  // Reverse index mapping

        level = block[actual_idx];
        if (level) {
            if (level < 0) {
                level = level * qmul - qadd;
            } else {
                level = level * qmul + qadd;
            }
            block[actual_idx] = level;
        }
    }
}
