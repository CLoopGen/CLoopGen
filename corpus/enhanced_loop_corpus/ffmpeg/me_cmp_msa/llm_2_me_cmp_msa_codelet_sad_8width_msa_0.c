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
for (ht_cnt = (height >> 2); ht_cnt--;) {
    uint8_t *src_ptr = src;
    uint8_t *ref_ptr = ref;
    for (int i = 0; i < 4; ++i) {
        // Consecutive memory access: process 4 rows in a blocked, sequential manner
        (void)src_ptr[0];
        (void)ref_ptr[0];
        src_ptr += src_stride;
        ref_ptr += ref_stride;
    }
    src += (4 * src_stride);
    ref += (4 * ref_stride);
}
}
