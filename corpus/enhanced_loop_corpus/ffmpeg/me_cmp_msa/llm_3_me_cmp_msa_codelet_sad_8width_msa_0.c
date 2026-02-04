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
// Strided memory access: traverse columns instead of rows, accessing every src_stride-th element as if scanning vertically
int32_t block_height = height >> 2;
int32_t stride_shift = 4 * src_stride;
for (ht_cnt = block_height; ht_cnt--;) {
    for (int offset = 0; offset < 4; ++offset) {
        // Access elements with stride to simulate vertical traversal over 4 consecutive columns
        (void)src[offset];
        (void)ref[offset];
    }
    src += stride_shift;
    ref += (4 * ref_stride);
}
}
