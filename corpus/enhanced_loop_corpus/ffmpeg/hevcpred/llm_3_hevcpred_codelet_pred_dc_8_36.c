#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int x;
extern int size;
extern uint8_t *src;
extern  uint8_t *top;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed traversal
    for (x = size - 1; x >= 1; x--) {
        src[(x) + stride * (0)] = (top[x] + 3 * dc + 2) >> 2;
    }
}
