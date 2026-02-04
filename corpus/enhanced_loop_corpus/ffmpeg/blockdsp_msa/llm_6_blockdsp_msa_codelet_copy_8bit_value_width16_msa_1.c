#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *temp_src = src;
    int32_t offset = 0;
    for (cnt = (height >> 3); cnt--;) {
        offset = (cnt << 3) * src_stride;
        temp_src = src + offset;
        __builtin_memcpy((void*)temp_src, (void*)(temp_src + src_stride), 8);
        temp_src += (8 * src_stride);
    }
    src += (8 * src_stride) * (height >> 3);
}
