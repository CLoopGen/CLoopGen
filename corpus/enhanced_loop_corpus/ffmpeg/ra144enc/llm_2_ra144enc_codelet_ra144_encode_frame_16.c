#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t lpc_coefs[10][32];
extern int shift[10];
extern int16_t block_coefs[4][10];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    int32_t* coef_ptr = &lpc_coefs[9][0];
    int* shift_ptr = &shift[9];
    int16_t* block_ptr = &block_coefs[3][0];
    int shift_val = *shift_ptr;
    for (i = 0; i < 10; i++) {
        block_ptr[i] = -(coef_ptr[i] * (1 << (12 - shift_val)));
    }
}
