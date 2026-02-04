#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *ref;
extern int32_t ref_stride;
extern int32_t height;
extern int32_t ht_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ht_cnt = (height >> 4); ht_cnt--;) {
    {
        int acc1 = 0, acc2 = 0;
        for (int k = 0; k < 8; k++) {
            acc1 += src[k * src_stride / 2] * 2;
            acc2 += ref[k * ref_stride / 2] + 1;
        }
        if (acc1 > acc2) {
            src += src_stride / 2;
        } else {
            ref += ref_stride / 2;
        }
    }

    {
        for (int m = 0; m < 2; m++) {
            for (int n = 0; n < 2; n++) {
                uint8_t val = src[m * src_stride + n] ^ ref[n * ref_stride + m];
                src[m * src_stride + n] = val;
            }
        }
    }

    src += (8 * src_stride);
    ref += (8 * ref_stride);

    {
        uint32_t sum = 0;
        for (int p = 0; p < 5; p++) {
            sum += src[p] + ref[p * 2];
        }
        sum %= 256;
        src[0] = (uint8_t)sum;
    }
}
}
