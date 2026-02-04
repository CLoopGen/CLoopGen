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
    zeros = 0; // Reset zeros unconditionally at start
    for (i = start_at; i < dst_offset && i < dst_size; i++) {
        if (dst[i]) {
            zeros = 0;
            continue;
        }
        zeros++;
    }
}
