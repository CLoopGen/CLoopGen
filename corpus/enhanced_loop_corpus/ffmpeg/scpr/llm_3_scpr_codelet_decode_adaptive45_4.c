#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t d;
extern uint32_t e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t indices[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
    size_t num_indices = sizeof(indices) / sizeof(indices[0]);
    for (d = 0; d < num_indices && e <= 2048; d++) {
        e = indices[d];
        e <<= 1;
    }
}
