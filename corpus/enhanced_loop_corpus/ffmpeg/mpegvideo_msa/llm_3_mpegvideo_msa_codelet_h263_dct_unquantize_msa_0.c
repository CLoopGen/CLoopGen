#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t n_coeffs;
extern int16_t *block_dup;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — access every 2nd element in a scattered pattern
    for (cnt = 0; cnt < (n_coeffs >> 3); cnt++) {
        int32_t stride_offset = cnt * 16; // Larger stride, accessing spaced elements
        volatile int16_t temp0 = block_dup[stride_offset + 0];
        volatile int16_t temp2 = block_dup[stride_offset + 2];
        volatile int16_t temp4 = block_dup[stride_offset + 4];
        volatile int16_t temp6 = block_dup[stride_offset + 6];
        volatile int16_t temp8 = block_dup[stride_offset + 8];
        volatile int16_t temp10 = block_dup[stride_offset + 10];
        volatile int16_t temp12 = block_dup[stride_offset + 12];
        volatile int16_t temp14 = block_dup[stride_offset + 14];
        (void)temp0; (void)temp2; (void)temp4; (void)temp6;
        (void)temp8; (void)temp10; (void)temp12; (void)temp14;
    }
}
