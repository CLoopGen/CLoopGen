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
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint16_t *ptr = (uint16_t *)(dst + y * linesize + x * sizeof(uint16_t));
    uint16_t *row_start = ptr - x;
    int remaining_in_row = width - x;
    for (i = 0; i < length; i++) {
        *ptr++ = pixel;
        remaining_in_row--;
        if (remaining_in_row == 0) {
            y++;
            if (y >= height)
                return;
            row_start = (uint16_t *)(dst + y * linesize);
            ptr = row_start;
            remaining_in_row = width;
        }
    }
}
