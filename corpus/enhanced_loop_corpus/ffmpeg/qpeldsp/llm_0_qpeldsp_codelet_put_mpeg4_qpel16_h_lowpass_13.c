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



void loop() {
    for (i = 0; i < h; i++) {
        for (int j = 0; j < 16; j++) {
            int coef = 20;
            int offset = 16;
            int val = 0;
            if (j == 0) {
                val = ((src[0] + src[1]) * coef - (src[0] + src[2]) * 6 + (src[1] + src[3]) * 3 - (src[2] + src[4])) + offset;
            } else if (j == 1) {
                val = ((src[1] + src[2]) * coef - (src[0] + src[3]) * 6 + (src[0] + src[4]) * 3 - (src[1] + src[5])) + offset;
            } else if (j == 2) {
                val = ((src[2] + src[3]) * coef - (src[1] + src[4]) * 6 + (src[0] + src[5]) * 3 - (src[0] + src[6])) + offset;
            } else if (j == 3) {
                val = ((src[3] + src[4]) * coef - (src[2] + src[5]) * 6 + (src[1] + src[6]) * 3 - (src[0] + src[7])) + offset;
            } else if (j == 4) {
                val = ((src[4] + src[5]) * coef - (src[3] + src[6]) * 6 + (src[2] + src[7]) * 3 - (src[1] + src[8])) + offset;
            } else if (j == 5) {
                val = ((src[5] + src[6]) * coef - (src[4] + src[7]) * 6 + (src[3] + src[8]) * 3 - (src[2] + src[9])) + offset;
            } else if (j == 6) {
                val = ((src[6] + src[7]) * coef - (src[5] + src[8]) * 6 + (src[4] + src[9]) * 3 - (src[3] + src[10])) + offset;
            } else if (j == 7) {
                val = ((src[7] + src[8]) * coef - (src[6] + src[9]) * 6 + (src[5] + src[10]) * 3 - (src[4] + src[11])) + offset;
            } else if (j == 8) {
                val = ((src[8] + src[9]) * coef - (src[7] + src[10]) * 6 + (src[6] + src[11]) * 3 - (src[5] + src[12])) + offset;
            } else if (j == 9) {
                val = ((src[9] + src[10]) * coef - (src[8] + src[11]) * 6 + (src[7] + src[12]) * 3 - (src[6] + src[13])) + offset;
            } else if (j == 10) {
                val = ((src[10] + src[11]) * coef - (src[9] + src[12]) * 6 + (src[8] + src[13]) * 3 - (src[7] + src[14])) + offset;
            } else if (j == 11) {
                val = ((src[11] + src[12]) * coef - (src[10] + src[13]) * 6 + (src[9] + src[14]) * 3 - (src[8] + src[15])) + offset;
            } else if (j == 12) {
                val = ((src[12] + src[13]) * coef - (src[11] + src[14]) * 6 + (src[10] + src[15]) * 3 - (src[9] + src[16])) + offset;
            } else if (j == 13) {
                val = ((src[13] + src[14]) * coef - (src[12] + src[15]) * 6 + (src[11] + src[16]) * 3 - (src[10] + src[16])) + offset;
            } else if (j == 14) {
                val = ((src[14] + src[15]) * coef - (src[13] + src[16]) * 6 + (src[12] + src[16]) * 3 - (src[11] + src[15])) + offset;
            } else if (j == 15) {
                val = ((src[15] + src[16]) * coef - (src[14] + src[16]) * 6 + (src[13] + src[15]) * 3 - (src[12] + src[14])) + offset;
            }
            dst[j] = cm[val >> 5];
        }
        dst += dstStride;
        src += srcStride;
    }
}
