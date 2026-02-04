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
    for (int outer = 1; outer < size; outer += 2) {
        for (y = outer; y < size && y < outer + 2; y++) {
            src[(0) + stride * (y)] = (left[y] + 3 * dc + 2) >> 2;
        }
    }
}
