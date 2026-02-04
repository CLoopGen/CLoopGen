#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ssize_t dst_offset;
extern size_t dst_size;
extern int zeros;
extern int start_at;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive two-element access to increase spatial locality
    for (i = start_at; i < dst_offset && i < dst_size - 1; i++) {
        if (!dst[i])
            zeros++;
        else
            zeros = 0;

        if (!dst[i + 1])
            zeros++;
        else
            zeros = 0;
    }
    // Handle last element if applicable
    if (i == dst_size - 1 && i < dst_offset) {
        if (!dst[i])
            zeros++;
        else
            zeros = 0;
    }
}
