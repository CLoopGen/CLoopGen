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
    cnt = (height >> 1);
    for (; cnt != 0; cnt--) {
        src += stride;
        if (cnt & 1) {
            continue;
        }
        src += stride;
    }
}
