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
    uint64_t local_mask = mask;
    unsigned int local_result = result;
    AVRational *local_depth = depth;
    for (; local_result > 0; --local_result, local_mask >>= 2) {
        if (local_mask & 1)
            local_depth->num += 2;
        if ((local_mask >> 1) & 1)
            local_depth->den += 2;
    }
    result = 0;
    mask = local_mask;
}
