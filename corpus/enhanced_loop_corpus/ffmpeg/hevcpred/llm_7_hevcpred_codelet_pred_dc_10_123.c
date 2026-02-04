#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int y;
extern int size;
extern uint16_t *src;
extern  uint16_t *left;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_y = 1;
    for (y = 1; y < size; y++) {
        if (y > 1) {
            src[(0) + stride * (y)] = (left[y] + 3 * src[(0) + stride * (prev_y)] + 2) >> 2;
        } else {
            src[(0) + stride * (y)] = (left[y] + 3 * dc + 2) >> 2;
        }
        prev_y = y;
    }
}
