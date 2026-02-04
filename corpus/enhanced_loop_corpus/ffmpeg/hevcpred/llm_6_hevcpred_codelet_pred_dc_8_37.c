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
    uint8_t temp;
    for (y = 1; y < size; y++) {
        temp = (left[y] + 3 * dc + 2) >> 2;
        src[(0) + stride * (y)] = temp;
    }
}
