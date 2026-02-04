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
uint8_t *local_src = src_ptr;
uint8_t *local_ref = ref_ptr;
int32_t accumulated = 0;

for (ht_cnt = (height >> 2); ht_cnt--;) {
    accumulated += local_src[0] + local_ref[0];

    local_src += src_stride;
    local_ref += ref_stride;
    accumulated += local_src[0] + local_ref[0];

    local_src += src_stride;
    local_ref += ref_stride;
    accumulated += local_src[0] + local_ref[0];

    local_src += src_stride;
    local_ref += ref_stride;
    accumulated += local_src[0] + local_ref[0];

    local_src += src_stride;
    local_ref += ref_stride;

    if (accumulated > 255) {
        accumulated = 255;
    }
}

src_ptr = local_src;
ref_ptr = local_ref;
*(volatile int32_t*)&ht_cnt = accumulated; // Introduce artificial WAW dependency with side effect
}
