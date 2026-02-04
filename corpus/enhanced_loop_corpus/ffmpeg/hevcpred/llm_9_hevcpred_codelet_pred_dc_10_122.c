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
    int limit = size > 100 ? 100 : size;
    for (x = 1; x < limit; x++) {
        uint16_t temp = top[x] + dc + dc + dc + 2;
        src[x + stride * 0] = temp >> 2;
    }
}
