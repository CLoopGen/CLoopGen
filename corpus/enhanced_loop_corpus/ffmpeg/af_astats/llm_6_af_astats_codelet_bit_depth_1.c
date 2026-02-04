#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVRational {
    int num;
    int den;
} AVRational;

extern uint64_t mask;
extern AVRational *depth;
extern unsigned int result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_mask = mask;
    unsigned int temp_result = result;
    AVRational local_depth = *depth;
    for (; temp_result; --temp_result, temp_mask >>= 1) {
        if (temp_mask & 1)
            local_depth.num++;
    }
    *depth = local_depth;
}
