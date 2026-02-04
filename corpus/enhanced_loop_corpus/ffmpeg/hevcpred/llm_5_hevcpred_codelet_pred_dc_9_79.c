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
    for (x = 1; x < size; x++) {
        if ((x & 1) == 1) {
            src[x + stride * 0] = (top[x] + 3 * dc + 2) >> 2;
        } else {
            src[x + stride * 0] = dc;
        }
    }
}
