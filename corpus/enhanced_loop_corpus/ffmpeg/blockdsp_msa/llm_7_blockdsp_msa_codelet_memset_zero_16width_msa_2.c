#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t stride;
extern int32_t height;
extern int8_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_src = src;
    int32_t offset = 0;
    for (cnt = (height / 2); cnt--;) {
        offset += stride * 2;
    }
    src = local_src + offset;
}
