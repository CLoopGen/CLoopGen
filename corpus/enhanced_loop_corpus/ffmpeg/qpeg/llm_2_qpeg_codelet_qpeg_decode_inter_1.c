#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int code;
extern int filled;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *ptr = dst;
    int remaining = code + 1;
    int local_filled = filled;
    int local_height = height;
    int local_stride = stride;
    int local_width = width;

    for (i = 0; i < remaining; i++) {
        *ptr++ = p;
        local_filled++;
        if (local_filled >= local_width) {
            ptr -= local_stride + 1;  // Move up one row using negative stride adjustment
            local_filled = 0;
            local_height--;
            if (local_height < 0)
                break;
        }
    }

    // Update side effects if needed (assuming globals should reflect final state)
    dst = ptr;
    filled = local_filled;
    height = local_height;
}
