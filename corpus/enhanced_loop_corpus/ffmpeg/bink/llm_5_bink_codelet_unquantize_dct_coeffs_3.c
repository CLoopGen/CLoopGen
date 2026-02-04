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
    for (i = 0; i < coef_count; i++) {
        int idx = coef_idx[i];
        int shifted = 11;
        int temp = (int)(block[scan[idx]] * quant[idx]);
        if ((temp >> shifted) != 0) {
            block[scan[idx]] = temp >> shifted;
        } else {
            block[scan[idx]] = 0;
        }
    }
}
