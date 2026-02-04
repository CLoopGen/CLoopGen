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
    for (; cnt <= n_coeffs; cnt++) {
        level = block[cnt];
        int16_t sign = (level > 0) - (level < 0);
        if (sign != 0) {
            level = level * qmul + (sign > 0 ? qadd : -qadd);
            block[cnt] = level;
        }
    }
}
