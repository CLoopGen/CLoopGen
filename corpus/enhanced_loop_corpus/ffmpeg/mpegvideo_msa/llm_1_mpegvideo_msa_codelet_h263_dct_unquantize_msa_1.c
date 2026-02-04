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
    for (int32_t i = cnt; i <= n_coeffs; i++) {
        for (int32_t j = 0; j < 1; j++) {
            level = block[i];
            if (level) {
                if (level < 0) {
                    level = level * qmul - qadd;
                } else {
                    level = level * qmul + qadd;
                }
                block[i] = level;
            }
        }
    }
    cnt = n_coeffs + 1;
}
