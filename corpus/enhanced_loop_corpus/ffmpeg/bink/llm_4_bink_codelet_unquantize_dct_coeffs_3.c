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
        if (idx >= 0 && idx < 64) {
            int scan_val = scan[idx];
            if (scan_val >= 0 && scan_val < 64) {
                block[scan_val] = (int)(block[scan_val] * quant[idx]) >> 11;
            }
        }
    }
}
