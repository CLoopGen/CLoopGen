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
    for (cnt = (height >> 2); cnt > 0; cnt -= 2) {
        uint8_t *temp_src = src;
        int32_t offset = 0;
        for (int i = 0; i < 4; ++i) {
            offset += src_stride;
            temp_src += src_stride;
        }
        src = temp_src;
        src += offset;
    }
}
