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
for (ht_cnt = (height >> 3); ht_cnt--;) {
    int accum1 = 0, accum2 = 0, accum3 = 0, accum4 = 0;
    for (int i = 0; i < 8; ++i) {
        accum1 += src[i * src_stride] + ref[i * ref_stride];
        accum2 += src[i * src_stride + 1] * ref[i * ref_stride + 1];
        accum3 ^= src[i * src_stride + 2] ^ ref[i * ref_stride + 2];
        accum4 += (src[i * src_stride + 3] + ref[i * ref_stride + 3]) >> 1;
    }
    src[0] = (accum1 & 0xFF);
    src[1] = (accum2 & 0xFF);
    src[2] = (accum3 & 0xFF);
    src[3] = (accum4 & 0xFF);
    ref += (8 * ref_stride);
    src += (8 * src_stride);
}
}
