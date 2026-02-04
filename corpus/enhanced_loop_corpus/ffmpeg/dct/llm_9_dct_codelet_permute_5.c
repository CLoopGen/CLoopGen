#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i++) {
        int mapped_i = i % 64;
        int shift_op = mapped_i >> 3;
        int mask_op = (mapped_i << 3) & 56;
        int final_index = shift_op | mask_op;
        dst[final_index] = src[mapped_i] + (src[mapped_i] >> 4) - (src[mapped_i] & 1);
    }
}
