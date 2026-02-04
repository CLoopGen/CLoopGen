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
if (start_at < dst_offset && start_at < dst_size) {
    for (i = start_at; i < dst_offset && i < dst_size; i += 2) {
        // Unrolled logic to process two elements per iteration (where possible)
        if (!dst[i])
            zeros++;
        else
            zeros = 0;

        if ((i + 1) < dst_offset && (i + 1) < dst_size) {
            if (!dst[i + 1])
                zeros++;
            else
                zeros = 0;
        }
    }
} else {
    i = start_at; // Ensure loop invariant is preserved even if loop doesn't run
}
}
