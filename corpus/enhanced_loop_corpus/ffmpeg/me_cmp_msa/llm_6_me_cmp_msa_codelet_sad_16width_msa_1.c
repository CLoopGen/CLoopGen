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
    uint8_t temp_src1 = src[0];
    uint8_t temp_ref1 = ref[0];
    src += (2 * src_stride);
    ref += (2 * ref_stride);
    uint8_t temp_src2 = src[0];
    uint8_t temp_ref2 = ref[0];
    src += (2 * src_stride);
    ref += (2 * ref_stride);
    
    // Introduce artificial WAW and WAR dependencies using temporary variables
    temp_src1 += temp_ref2;
    temp_ref1 += temp_src2;
    src[-(ptrdiff_t)(2 * src_stride)] = temp_src1;
    ref[-(ptrdiff_t)(2 * ref_stride)] = temp_ref1;
}
}
