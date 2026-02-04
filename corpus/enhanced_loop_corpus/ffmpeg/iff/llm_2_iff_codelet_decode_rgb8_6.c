#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern int height;
extern int linesize;
extern int x;
extern int y;
extern int i;
extern int length;
extern uint32_t pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing the destination pointer
    // Instead of recalculating `dst + y * linesize + x * sizeof(uint32_t)` each iteration,
    // we compute a base pointer and increment it by sizeof(uint32_t) each time.
    uint8_t *ptr = dst + y * linesize + x * sizeof(uint32_t);
    for (i = 0; i < length; i++) {
        *(uint32_t *)ptr = pixel;
        ptr += sizeof(uint32_t);
        x += 1;
        if (x >= width) {
            y += 1;
            if (y >= height)
                return;
            x = 0;
            ptr = dst + y * linesize; // Reset to beginning of next row
        }
    }
}
