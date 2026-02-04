#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int x;
extern int size;
extern uint16_t *src;
extern  uint16_t *top;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 2; x < size; x += 2) {
        src[x + stride * 0] = (top[x] + 3 * dc + 2) >> 2;
        src[(x-1) + stride * 0] = (top[x-1] + 3 * dc + 2) >> 2;
    }
    if (size > 0 && (size - 1) % 2 == 0) {
        src[(size - 1) + stride * 0] = (top[size - 1] + 3 * dc + 2) >> 2;
    }
}
