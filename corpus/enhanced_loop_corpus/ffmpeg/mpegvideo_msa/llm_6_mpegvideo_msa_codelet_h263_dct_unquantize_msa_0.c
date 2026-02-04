#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t n_coeffs;
extern int16_t *block_dup;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t i;
    int16_t *temp = block_dup;
    for (i = 0; i < (n_coeffs >> 3); i++) {
        temp[0] = temp[-8];
        temp += 8;
    }
    block_dup = temp;
}
