#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with local array buffering to improve spatial locality
    int16_t tmp_local[8];
    uint8_t src_local[11];
    
    for (i = 0; i < h + 5; i++) {
        // Prefetch data into local arrays to enable consecutive access pattern
        for (int j = 0; j < 11; j++) {
            src_local[j] = src[j - 2 + 2]; // Normalize indexing: -2..+8 becomes 0..10
        }

        tmp_local[0] = (src_local[2] + src_local[3]) * 20 - (src_local[1] + src_local[4]) * 5 + (src_local[0] + src_local[5]) + pad;
        tmp_local[1] = (src_local[3] + src_local[4]) * 20 - (src_local[2] + src_local[5]) * 5 + (src_local[1] + src_local[6]) + pad;
        tmp_local[2] = (src_local[4] + src_local[5]) * 20 - (src_local[3] + src_local[6]) * 5 + (src_local[2] + src_local[7]) + pad;
        tmp_local[3] = (src_local[5] + src_local[6]) * 20 - (src_local[4] + src_local[7]) * 5 + (src_local[3] + src_local[8]) + pad;
        tmp_local[4] = (src_local[6] + src_local[7]) * 20 - (src_local[5] + src_local[8]) * 5 + (src_local[4] + src_local[9]) + pad;
        tmp_local[5] = (src_local[7] + src_local[8]) * 20 - (src_local[6] + src_local[9]) * 5 + (src_local[5] + src_local[10]) + pad;
        tmp_local[6] = (src_local[8] + src_local[9]) * 20 - (src_local[7] + src_local[10]) * 5 + (src_local[6] + src_local[11]) + pad;
        tmp_local[7] = (src_local[9] + src_local[10]) * 20 - (src_local[8] + src_local[11]) * 5 + (src_local[7] + src_local[12]) + pad;

        // Store results in a burst to tmp using stride
        for (int k = 0; k < 8; k++) {
            tmp[k] = tmp_local[k];
        }

        tmp += tmpStride;
        src += srcStride;
    }
}
