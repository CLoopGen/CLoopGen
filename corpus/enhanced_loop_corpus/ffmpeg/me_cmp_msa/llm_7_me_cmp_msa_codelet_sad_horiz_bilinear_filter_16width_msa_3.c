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
    uint8_t *local_src = src;
    uint8_t *local_ref = ref;
    int32_t offset = 0;
    for (ht_cnt = (height >> 3); ht_cnt--;) {
        offset = (ht_cnt % 4) * 4;
        local_src[offset] = local_ref[offset];
        local_ref += (4 * ref_stride);
        local_src += (4 * src_stride);
        local_ref[offset] = local_src[offset];
        local_src += (4 * src_stride);
        local_ref += (4 * ref_stride);
    }
    // Update original pointers after loop
    src = local_src;
    ref = local_ref;
}
