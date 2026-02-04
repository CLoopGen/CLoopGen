#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t stride;
extern uint8_t *tmp_dst;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (row = 16; row--;) {
        for (int32_t inner = 1; inner > 0; inner--) {
            tmp_dst += stride;
        }
    }
}
