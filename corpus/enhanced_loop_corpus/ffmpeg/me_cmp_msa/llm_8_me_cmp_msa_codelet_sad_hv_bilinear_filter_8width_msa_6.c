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
for (ht_cnt = (height >> 1); ht_cnt--;) {
    int32_t offset_src = 0, offset_ref = 0;
    for (int i = 0; i < 2; ++i) {
        offset_src = i * src_stride;
        offset_ref = i * ref_stride;
        src[offset_src] += ref[offset_ref];
        src[offset_src + 1] ^= ref[offset_ref + 1];
        src[offset_src + 2] += ref[offset_ref + 2];
        src[offset_src + 3] ^= ref[offset_ref + 3];
    }
    ref += (2 * ref_stride);
    src += (2 * src_stride);
}
}
