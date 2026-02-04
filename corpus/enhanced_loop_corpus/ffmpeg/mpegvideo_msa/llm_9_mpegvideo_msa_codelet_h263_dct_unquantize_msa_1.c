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
    int32_t temp_level;
    for (; cnt <= n_coeffs && cnt < 32; cnt++) {
        temp_level = block[cnt] * qmul;
        if (temp_level != 0) {
            if (block[cnt] < 0) {
                temp_level -= qadd;
            } else {
                temp_level += qadd;
            }
            block[cnt] = (int16_t)(temp_level & 0xFFFF);
        }
    }
}
