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
    for (y = 2; y < size; y += 2) {
        src[(0) + stride * (y)] = (left[y] + 5 * dc + 3) >> 3;
        if (y + 1 < size) {
            src[(0) + stride * (y + 1)] = (left[y + 1] + dc + 1) >> 1;
        }
    }
}
