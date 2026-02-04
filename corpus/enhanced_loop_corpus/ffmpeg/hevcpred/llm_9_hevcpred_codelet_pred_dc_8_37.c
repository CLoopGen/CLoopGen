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
    const int unroll_factor = 4;
    int limit = size - (size % unroll_factor);
    for (y = 1; y < limit; y += unroll_factor) {
        src[stride * y]           = (left[y]     + 2 * dc + 1) >> 2;
        src[stride * (y + 1)]     = (left[y + 1] + 3 * dc + 1) >> 2;
        src[stride * (y + 2)]     = (left[y + 2] + 4 * dc + 1) >> 2;
        src[stride * (y + 3)]     = (left[y + 3] + 5 * dc + 1) >> 2;
    }
    for (; y < size; y++) {
        src[stride * y] = (left[y] + 3 * dc + 2) >> 2;
    }
}
