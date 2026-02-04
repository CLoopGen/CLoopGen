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
    int32_t i;
    for (i = 0; i < height * 2; i++) {
        if (i % 2 == 0) {
            src += stride;
        } else {
            src += stride;
        }
    }
}
