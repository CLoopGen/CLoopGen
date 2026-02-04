#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Local Buffering
    // Instead of strided access, we preload a block of src data into a local array to promote spatial locality.
    uint8_t src_buffer[32]; // Larger than needed to avoid overflow
    for (i = 0; i < h; i++) {
        // Prefetch a block of src into local buffer for consecutive access
        for (int j = 0; j < 17; j++) {
            src_buffer[j] = src[j];
        }

        dst[0] = cm[(((src_buffer[0] + src_buffer[1]) * 20 - (src_buffer[0] + src_buffer[2]) * 6 + (src_buffer[1] + src_buffer[3]) * 3 - (src_buffer[2] + src_buffer[4])) + 15) >> 5];
        dst[1] = cm[(((src_buffer[1] + src_buffer[2]) * 20 - (src_buffer[0] + src_buffer[3]) * 6 + (src_buffer[0] + src_buffer[4]) * 3 - (src_buffer[1] + src_buffer[5])) + 15) >> 5];
        dst[2] = cm[(((src_buffer[2] + src_buffer[3]) * 20 - (src_buffer[1] + src_buffer[4]) * 6 + (src_buffer[0] + src_buffer[5]) * 3 - (src_buffer[0] + src_buffer[6])) + 15) >> 5];
        dst[3] = cm[(((src_buffer[3] + src_buffer[4]) * 20 - (src_buffer[2] + src_buffer[5]) * 6 + (src_buffer[1] + src_buffer[6]) * 3 - (src_buffer[0] + src_buffer[7])) + 15) >> 5];
        dst[4] = cm[(((src_buffer[4] + src_buffer[5]) * 20 - (src_buffer[3] + src_buffer[6]) * 6 + (src_buffer[2] + src_buffer[7]) * 3 - (src_buffer[1] + src_buffer[8])) + 15) >> 5];
        dst[5] = cm[(((src_buffer[5] + src_buffer[6]) * 20 - (src_buffer[4] + src_buffer[7]) * 6 + (src_buffer[3] + src_buffer[8]) * 3 - (src_buffer[2] + src_buffer[9])) + 15) >> 5];
        dst[6] = cm[(((src_buffer[6] + src_buffer[7]) * 20 - (src_buffer[5] + src_buffer[8]) * 6 + (src_buffer[4] + src_buffer[9]) * 3 - (src_buffer[3] + src_buffer[10])) + 15) >> 5];
        dst[7] = cm[(((src_buffer[7] + src_buffer[8]) * 20 - (src_buffer[6] + src_buffer[9]) * 6 + (src_buffer[5] + src_buffer[10]) * 3 - (src_buffer[4] + src_buffer[11])) + 15) >> 5];
        dst[8] = cm[(((src_buffer[8] + src_buffer[9]) * 20 - (src_buffer[7] + src_buffer[10]) * 6 + (src_buffer[6] + src_buffer[11]) * 3 - (src_buffer[5] + src_buffer[12])) + 15) >> 5];
        dst[9] = cm[(((src_buffer[9] + src_buffer[10]) * 20 - (src_buffer[8] + src_buffer[11]) * 6 + (src_buffer[7] + src_buffer[12]) * 3 - (src_buffer[6] + src_buffer[13])) + 15) >> 5];
        dst[10] = cm[(((src_buffer[10] + src_buffer[11]) * 20 - (src_buffer[9] + src_buffer[12]) * 6 + (src_buffer[8] + src_buffer[13]) * 3 - (src_buffer[7] + src_buffer[14])) + 15) >> 5];
        dst[11] = cm[(((src_buffer[11] + src_buffer[12]) * 20 - (src_buffer[10] + src_buffer[13]) * 6 + (src_buffer[9] + src_buffer[14]) * 3 - (src_buffer[8] + src_buffer[15])) + 15) >> 5];
        dst[12] = cm[(((src_buffer[12] + src_buffer[13]) * 20 - (src_buffer[11] + src_buffer[14]) * 6 + (src_buffer[10] + src_buffer[15]) * 3 - (src_buffer[9] + src_buffer[16])) + 15) >> 5];
        dst[13] = cm[(((src_buffer[13] + src_buffer[14]) * 20 - (src_buffer[12] + src_buffer[15]) * 6 + (src_buffer[11] + src_buffer[16]) * 3 - (src_buffer[10] + src_buffer[16])) + 15) >> 5];
        dst[14] = cm[(((src_buffer[14] + src_buffer[15]) * 20 - (src_buffer[13] + src_buffer[16]) * 6 + (src_buffer[12] + src_buffer[16]) * 3 - (src_buffer[11] + src_buffer[15])) + 15) >> 5];
        dst[15] = cm[(((src_buffer[15] + src_buffer[16]) * 20 - (src_buffer[14] + src_buffer[16]) * 6 + (src_buffer[13] + src_buffer[15]) * 3 - (src_buffer[12] + src_buffer[14])) + 15) >> 5];

        dst += dstStride;
        src += srcStride;
    }
}
