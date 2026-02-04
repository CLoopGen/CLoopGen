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
    uint16_t prev = 0;
    for (x = 1; x < size; x++) {
        uint16_t current = (top[x] + 3 * dc + 2 + prev) >> 2;
        src[x + stride * 0] = current;
        prev = current;
    }
}
