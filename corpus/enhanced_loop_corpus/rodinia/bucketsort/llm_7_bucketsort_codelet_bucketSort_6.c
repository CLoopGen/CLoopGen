#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp = h_offsets[0];
    for (int i = (1 << 10) - 1; i >= 1; i--) {
        uint32_t next_temp = h_offsets[i - 1];
        h_offsets[i] = temp;
        temp = next_temp;
    }
}
