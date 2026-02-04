#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t stride;
extern uint8_t *tmp_dst;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t j, k;
    for (j = 0; j < 4; ++j) {
        for (k = 0; k < 4; ++k) {
            tmp_dst += stride;
        }
    }
}
