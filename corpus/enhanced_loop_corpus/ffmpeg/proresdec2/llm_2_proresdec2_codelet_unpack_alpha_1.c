#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  int decode_precision;
extern int i;
extern int idx;
extern int val;
extern int alpha_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pre-computed base pointer and stride of 1
    uint16_t *base_dst = dst + idx;
    int shift = (decode_precision == 10) ? 6 : 4;
    for (i = 0; i < val; i++) {
        base_dst[i] = (alpha_val >> shift);
    }
    idx += val;  // update idx to reflect new position
}
