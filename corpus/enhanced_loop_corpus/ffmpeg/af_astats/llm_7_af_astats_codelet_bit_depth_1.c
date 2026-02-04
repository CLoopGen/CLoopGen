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
    unsigned int i;
    int num_updates = 0;
    for (i = 0; i < result; ++i, temp_mask >>= 1) {
        if (temp_mask & 1)
            num_updates++;
    }
    depth->num += num_updates;
    result = 0;
}
