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
        // Variant 1: Consecutive memory access with pointer pre-increment and local caching
        uint8_t *src0 = src;
        uint8_t *src1 = src + src_stride;
        uint8_t *src2 = src + 2*src_stride;
        uint8_t *src3 = src + 3*src_stride;
        uint8_t *src4 = src + 4*src_stride;
        uint8_t *src5 = src + 5*src_stride;
        uint8_t *src6 = src + 6*src_stride;
        uint8_t *src7 = src + 7*src_stride;

        uint8_t *ref0 = ref;
        uint8_t *ref1 = ref + ref_stride;
        uint8_t *ref2 = ref + 2*ref_stride;
        uint8_t *ref3 = ref + 3*ref_stride;
        uint8_t *ref4 = ref + 4*ref_stride;
        uint8_t *ref5 = ref + 5*ref_stride;
        uint8_t *ref6 = ref + 6*ref_stride;
        uint8_t *ref7 = ref + 7*ref_stride;

        // Simulate processing of consecutive rows using cached pointers
        { }
        { }
        { }
        { }

        src += (8 * src_stride);
        ref += (8 * ref_stride);

        { }
        { }
        { }
        { }
    }
}
