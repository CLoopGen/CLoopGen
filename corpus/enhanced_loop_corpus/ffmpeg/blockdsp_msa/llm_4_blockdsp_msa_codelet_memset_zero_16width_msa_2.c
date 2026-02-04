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
    cnt = height / 2;
    for (; cnt > 0; cnt--) {
        if (stride != 0) {
            src += stride * 2;
        }
    }
}
