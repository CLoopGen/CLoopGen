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
    for (i = 0; i < h; i++) {
        // Use strided memory access with precomputed offsets for improved locality and vectorization potential
        const int16_t coefficients[4][4] = {
            {20, -6, 3, -1},  // applied to pairs: (j,j+1), (j-1,j+2), (j-2,j+3), (j-3,j+4)
            {20, -6, 3, -1},
            {20, -6, 3, -1},
            {20, -6, 3, -1}
        };

        int offset_table[17];
        for (int idx = 0; idx < 17; idx++) {
            offset_table[idx] = idx;
        }

        for (int j = 0; j < 16; j++) {
            int s0 = src[offset_table[j]] + src[offset_table[j + 1]];
            int s1 = (j >= 1) ? src[offset_table[j - 1]] + src[offset_table[j + 2]] : src[offset_table[0]] + src[offset_table[2]];
            int s2 = (j >= 2) ? src[offset_table[j - 2]] + src[offset_table[j + 3]] : src[offset_table[0]] + src[offset_table[3]];
            int s3 = (j >= 3) ? src[offset_table[j - 3]] + src[offset_table[j + 4]] : src[offset_table[0]] + src[offset_table[4]];

            int result = (s0 * coefficients[0][0] + 
                          s1 * coefficients[0][1] + 
                          s2 * coefficients[0][2] + 
                          s3 * coefficients[0][3] + 16) >> 5;

            dst[j] = cm[result & 0xFF];  // Bound-check via masking assuming cm is 256-byte aligned
        }

        // Final write for the last pixel using symmetric padding on boundaries
        dst[15] = cm[(((src[15] + src[16]) * 20 - (src[14] + src[16]) * 6 + 
                      (src[13] + src[15]) * 3 - (src[12] + src[14]) + 16) >> 5)];

        // Stride advance
        dst += dstStride;
        src += srcStride;
    }
}
