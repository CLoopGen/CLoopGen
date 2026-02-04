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
    block[scan[idx]] = (int)(block[scan[idx]] * quant[idx]) >> 11;
}

}
