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
    if (coef_count > 0) {
        for (i = 0; i < coef_count; i += 2) {
            int idx1 = coef_idx[i];
            block[scan[idx1]] = (int)(block[scan[idx1]] * quant[idx1]) >> 11;

            if (i + 1 < coef_count) {
                int idx2 = coef_idx[i + 1];
                block[scan[idx2]] = (int)(block[scan[idx2]] * quant[idx2]) >> 11;
            }
        }
    }
}
