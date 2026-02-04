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
    int8_t outer_cnt, inner_cnt;
    for (outer_cnt = (height / 4); outer_cnt--; ) {
        for (inner_cnt = 2; inner_cnt--; ) {
            src += stride;
            src += stride;
        }
    }
}
