#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t idct_simple_mmx_perm[64];
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    int inner_i;
    for (outer_i = 0; outer_i < 8; outer_i++) {
        for (inner_i = 0; inner_i < 8; inner_i++) {
            i = outer_i * 8 + inner_i;
            dst[idct_simple_mmx_perm[i]] = src[i];
        }
    }
}
