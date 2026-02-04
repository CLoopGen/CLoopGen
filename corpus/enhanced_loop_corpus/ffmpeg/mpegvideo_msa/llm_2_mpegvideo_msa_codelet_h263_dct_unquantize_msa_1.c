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
    // Variant 1: Strided memory access with stride of 2
    for (int32_t idx = 0; idx <= n_coeffs; idx += 2) {
        int32_t cnt1 = idx;
        int32_t cnt2 = idx + 1;

        // Process first element in stride
        level = block[cnt1];
        if (level) {
            if (level < 0) {
                level = level * qmul - qadd;
            } else {
                level = level * qmul + qadd;
            }
            block[cnt1] = level;
        }

        // Process second element if within bounds
        if (cnt2 <= n_coeffs) {
            level = block[cnt2];
            if (level) {
                if (level < 0) {
                    level = level * qmul - qadd;
                } else {
                    level = level * qmul + qadd;
                }
                block[cnt2] = level;
            }
        }
    }
}
