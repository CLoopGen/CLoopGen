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
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Local Buffering
    // Instead of strided access, load a local block of src into a temporary array to promote spatial locality.
    int16_t tmp_local[8];
    uint16_t src_local[8 + 2]; // includes padding for [-2] and [3+5] accesses

    for (i = 0; i < h + 5; i++) {
        // Prefetch a block of src values to enable consecutive access pattern
        for (int j = 0; j < 8 + 2; j++) {
            src_local[j] = src[j - 2];
        }

        // Compute using local array to eliminate negative indexing and improve cache behavior
        tmp_local[0] = (src_local[2] + src_local[3]) * 20 - (src_local[1] + src_local[4]) * 5 + (src_local[0] + src_local[5]) + pad;
        tmp_local[1] = (src_local[3] + src_local[4]) * 20 - (src_local[2] + src_local[5]) * 5 + (src_local[1] + src_local[6]) + pad;
        tmp_local[2] = (src_local[4] + src_local[5]) * 20 - (src_local[3] + src_local[6]) * 5 + (src_local[2] + src_local[7]) + pad;
        tmp_local[3] = (src_local[5] + src_local[6]) * 20 - (src_local[4] + src_local[7]) * 5 + (src_local[3] + src_local[8]) + pad;

        // Store results to tmp with stride
        for (int k = 0; k < 4; k++) {
            tmp[k] = tmp_local[k];
        }

        tmp += tmpStride;
        src += srcStride;
    }
}
