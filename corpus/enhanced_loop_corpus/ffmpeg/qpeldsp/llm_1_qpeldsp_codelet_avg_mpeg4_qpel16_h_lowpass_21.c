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
    int j;
    for (j = 0; j < 16; j += 2) {
        // Unroll two iterations at a time to reduce loop overhead
        int idx1, idx2;

        // First of the pair
        {
            int s0 = src[(j == 0) ? 0 : j-1];
            int s1 = src[j];
            int s2 = src[j+1];
            int s3 = src[j+2];
            int s4 = (j+3 <= 16) ? src[j+3] : src[16];
            int s5 = (j+4 <= 16) ? src[j+4] : src[16];

            int t1 = (s1 + s2) * 20;
            int t2 = (s0 + s3) * 6;
            int t3 = (j >= 2 ? (src[j-2] + s4) : (j == 1 ? (src[0] + s4) : (src[1] + s3))) * 3;
            int t4 = (j >= 3 ? (src[j-3] + (j+4 <= 16 ? src[j+4] : src[16])) : 
                    (j == 2 ? (src[0] + src[7]) : 
                    (j == 1 ? (src[1] + src[5]) : (src[2] + src[4]))));

            idx1 = ((t1 - t2 + t3 - t4) + 16) >> 5;
            dst[j] = ((dst[j] + cm[idx1] + 1) >> 1);
        }

        // Second of the pair, if within bounds
        if (j + 1 < 16) {
            int j2 = j + 1;
            int s0 = src[(j2 == 0) ? 0 : j2-1];
            int s1 = src[j2];
            int s2 = src[j2+1];
            int s3 = src[j2+2];
            int s4 = (j2+3 <= 16) ? src[j2+3] : src[16];
            int s5 = (j2+4 <= 16) ? src[j2+4] : src[16];

            int t1 = (s1 + s2) * 20;
            int t2 = (s0 + s3) * 6;
            int t3 = (j2 >= 2 ? (src[j2-2] + s4) : (j2 == 1 ? (src[0] + s4) : (src[1] + s3))) * 3;
            int t4 = (j2 >= 3 ? (src[j2-3] + (j2+4 <= 16 ? src[j2+4] : src[16])) : 
                    (j2 == 2 ? (src[0] + src[7]) : 
                    (j2 == 1 ? (src[1] + src[5]) : (src[2] + src[4]))));

            idx2 = ((t1 - t2 + t3 - t4) + 16) >> 5;
            dst[j2] = ((dst[j2] + cm[idx2] + 1) >> 1);
        }
    }
    dst += dstStride;
    src += srcStride;
}
}
