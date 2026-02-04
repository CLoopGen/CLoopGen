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
    for (x = 1; x < size; x++) {
        src[(x) + stride * (0)] = (top[x] + 3 * dc + 2) >> 2;
        if (x + 1 < size) {
            x++;
            src[(x) + stride * (0)] = (top[x] + 3 * dc + 2) >> 2;
        }
    }
}
