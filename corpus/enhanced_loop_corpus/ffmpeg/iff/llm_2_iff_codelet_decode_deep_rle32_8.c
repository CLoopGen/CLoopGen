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
extern int size;
extern uint32_t pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing the destination pointer
    // Instead of recalculating dst + y * linesize + x * 4 each iteration, traverse consecutively
    uint32_t *dest = (uint32_t *)(dst + y * linesize + x * 4);
    int remaining_width = width - x;
    int idx = 0;
    while (idx < size && y < height) {
        int count = (remaining_width <= size - idx) ? remaining_width : (size - idx);
        for (int j = 0; j < count; j++) {
            dest[j] = pixel;
            idx++;
        }
        dest += width;  // Jump to next row (in units of uint32_t)
        y++;
        x = 0;
        remaining_width = width;
    }
}
