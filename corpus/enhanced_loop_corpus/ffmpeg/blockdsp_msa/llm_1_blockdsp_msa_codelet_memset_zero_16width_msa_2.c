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
    int8_t i;
    if (cnt = (height / 2)) {
        for (i = 0; i < cnt; i++) {
            src += stride;
            src += stride;
        }
    }
}
