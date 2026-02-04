#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int y;
extern int size;
extern uint8_t *src;
extern  uint8_t *left;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_y = 0;
    for (y = 1; y < size; y++) {
        src[(0) + stride * (y)] = (left[prev_y] + 3 * dc + 2) >> 2;
        prev_y = y;
    }
}
