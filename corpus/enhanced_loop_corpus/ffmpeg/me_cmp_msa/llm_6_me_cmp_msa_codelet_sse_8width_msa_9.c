#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src_ptr;
extern int32_t src_stride;
extern uint8_t *ref_ptr;
extern int32_t ref_stride;
extern int32_t height;
extern int32_t ht_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ht_cnt = (height >> 2); ht_cnt--;) {
    uint32_t temp_src[4], temp_ref[4];
    temp_src[0] = *(uint32_t*)(src_ptr + 0 * src_stride);
    temp_src[1] = *(uint32_t*)(src_ptr + 1 * src_stride);
    temp_src[2] = *(uint32_t*)(src_ptr + 2 * src_stride);
    temp_src[3] = *(uint32_t*)(src_ptr + 3 * src_stride);

    temp_ref[0] = *(uint32_t*)(ref_ptr + 0 * ref_stride);
    temp_ref[1] = *(uint32_t*)(ref_ptr + 1 * ref_stride);
    temp_ref[2] = *(uint32_t*)(ref_ptr + 2 * ref_stride);
    temp_ref[3] = *(uint32_t*)(ref_ptr + 3 * ref_stride);

    src_ptr += (4 * src_stride);
    ref_ptr += (4 * ref_stride);

    temp_src[0] ^= temp_ref[0];
    temp_src[1] ^= temp_ref[1];
    temp_src[2] ^= temp_ref[2];
    temp_src[3] ^= temp_ref[3];

    *(uint32_t*)(src_ptr - 4 * src_stride) = temp_src[0];
    *(uint32_t*)(src_ptr - 3 * src_stride) = temp_src[1];
    *(uint32_t*)(src_ptr - 2 * src_stride) = temp_src[2];
    *(uint32_t*)(src_ptr - 1 * src_stride) = temp_src[3];
}
}
