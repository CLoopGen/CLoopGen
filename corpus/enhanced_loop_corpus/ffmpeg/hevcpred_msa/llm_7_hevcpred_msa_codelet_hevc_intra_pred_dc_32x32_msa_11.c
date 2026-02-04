#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;  // Remove direct dependency on global dst in each update
    int32_t double_stride = stride << 1;
    for (row = 16; row--;) {
        local_dst += double_stride;  // Eliminate WAW on dst until loop exit
    }
    dst = local_dst;  // Single write-back to global dst after loop (removes loop-carried WAW on dst)
}
