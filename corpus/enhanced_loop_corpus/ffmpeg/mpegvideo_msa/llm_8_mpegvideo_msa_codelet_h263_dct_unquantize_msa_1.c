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



void loop(){
    for (; cnt <= n_coeffs; cnt += 2) {
        int16_t val1 = block[cnt];
        int16_t val2 = (cnt + 1 <= n_coeffs) ? block[cnt + 1] : 0;
        int32_t level1 = 0, level2 = 0;

        if (val1) {
            level1 = (val1 < 0) ? val1 * qmul - qadd : val1 * qmul + qadd;
            block[cnt] = level1;
        }

        if (val2) {
            level2 = (val2 < 0) ? val2 * qmul - qadd : val2 * qmul + qadd;
            block[cnt + 1] = level2;
        }
    }
}
