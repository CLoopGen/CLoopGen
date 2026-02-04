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
uint8_t local_accum[16] = {0};
int offset = 0;
for (ht_cnt = (height >> 3); ht_cnt--;) {
    for (int step = 0; step < 8; step++) {
        int idx = step % 16;
        local_accum[idx] += src[step * src_stride / 2] + ref[step * ref_stride / 2];
        if (local_accum[idx] > 128) {
            src[step * src_stride / 2] = local_accum[idx] - ref[step * ref_stride / 2];
        }
    }
    offset += local_accum[0];
    src += (4 * src_stride) + (offset % 3);
    ref += (5 * ref_stride);
    for (int step = 0; step < 8; step++) {
        int idx = (step + 8) % 16;
        local_accum[idx] ^= src[step * src_stride / 2] ^ ref[step * ref_stride / 2];
        ref[step * ref_stride / 2] = local_accum[idx] + 1;
    }
    offset -= local_accum[15];
    src += (4 * src_stride);
    ref += (3 * ref_stride) + (offset & 1);
}
}
