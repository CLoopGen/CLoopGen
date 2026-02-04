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
    src += src_stride;
    ref += ref_stride;
    src += src_stride;
    ref += ref_stride;
    src += src_stride;
    ref += ref_stride;
    src += src_stride;
    ref += ref_stride;
}
}
