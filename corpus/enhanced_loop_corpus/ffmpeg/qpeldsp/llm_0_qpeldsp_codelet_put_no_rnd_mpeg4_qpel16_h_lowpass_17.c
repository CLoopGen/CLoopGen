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
        for (int j = 0; j < 17; j++) {
            int sum;
            if (j == 0) {
                sum = ((src[0] + src[1]) * 20 - (src[0] + src[2]) * 6 + (src[1] + src[3]) * 3 - (src[2] + src[4])) + 15;
            } else if (j == 1) {
                sum = ((src[1] + src[2]) * 20 - (src[0] + src[3]) * 6 + (src[0] + src[4]) * 3 - (src[1] + src[5])) + 15;
            } else if (j == 2) {
                sum = ((src[2] + src[3]) * 20 - (src[1] + src[4]) * 6 + (src[0] + src[5]) * 3 - (src[0] + src[6])) + 15;
            } else if (j == 3) {
                sum = ((src[3] + src[4]) * 20 - (src[2] + src[5]) * 6 + (src[1] + src[6]) * 3 - (src[0] + src[7])) + 15;
            } else if (j == 4) {
                sum = ((src[4] + src[5]) * 20 - (src[3] + src[6]) * 6 + (src[2] + src[7]) * 3 - (src[1] + src[8])) + 15;
            } else if (j == 5) {
                sum = ((src[5] + src[6]) * 20 - (src[4] + src[7]) * 6 + (src[3] + src[8]) * 3 - (src[2] + src[9])) + 15;
            } else if (j == 6) {
                sum = ((src[6] + src[7]) * 20 - (src[5] + src[8]) * 6 + (src[4] + src[9]) * 3 - (src[3] + src[10])) + 15;
            } else if (j == 7) {
                sum = ((src[7] + src[8]) * 20 - (src[6] + src[9]) * 6 + (src[5] + src[10]) * 3 - (src[4] + src[11])) + 15;
            } else if (j == 8) {
                sum = ((src[8] + src[9]) * 20 - (src[7] + src[10]) * 6 + (src[6] + src[11]) * 3 - (src[5] + src[12])) + 15;
            } else if (j == 9) {
                sum = ((src[9] + src[10]) * 20 - (src[8] + src[11]) * 6 + (src[7] + src[12]) * 3 - (src[6] + src[13])) + 15;
            } else if (j == 10) {
                sum = ((src[10] + src[11]) * 20 - (src[9] + src[12]) * 6 + (src[8] + src[13]) * 3 - (src[7] + src[14])) + 15;
            } else if (j == 11) {
                sum = ((src[11] + src[12]) * 20 - (src[10] + src[13]) * 6 + (src[9] + src[14]) * 3 - (src[8] + src[15])) + 15;
            } else if (j == 12) {
                sum = ((src[12] + src[13]) * 20 - (src[11] + src[14]) * 6 + (src[10] + src[15]) * 3 - (src[9] + src[16])) + 15;
            } else if (j == 13) {
                sum = ((src[13] + src[14]) * 20 - (src[12] + src[15]) * 6 + (src[11] + src[16]) * 3 - (src[10] + src[16])) + 15;
            } else if (j == 14) {
                sum = ((src[14] + src[15]) * 20 - (src[13] + src[16]) * 6 + (src[12] + src[16]) * 3 - (src[11] + src[15])) + 15;
            } else if (j == 15) {
                sum = ((src[15] + src[16]) * 20 - (src[14] + src[16]) * 6 + (src[13] + src[15]) * 3 - (src[12] + src[14])) + 15;
            }
            if (j < 16) {
                dst[j] = cm[sum >> 5];
            }
        }
        dst += dstStride;
        src += srcStride;
    }
}
