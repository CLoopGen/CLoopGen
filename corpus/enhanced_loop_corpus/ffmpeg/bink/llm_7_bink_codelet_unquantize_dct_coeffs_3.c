#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t block[64];
extern  uint32_t quant[64];
extern int coef_count;
extern int coef_idx[64];
extern  uint8_t *scan;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int acc = 0;
    for (i = 0; i < coef_count; i++) {
        int idx = coef_idx[i];
        acc += block[scan[idx]]; 
        block[scan[idx]] = (int)(acc * quant[idx]) >> 11;
    }
}
