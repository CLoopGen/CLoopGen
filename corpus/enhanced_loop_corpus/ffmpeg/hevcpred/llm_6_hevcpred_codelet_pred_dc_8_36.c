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
    uint8_t temp;
    for (x = 1; x < size; x++) {
        temp = (top[x] + 3 * dc + 2) >> 2;
        src[x + stride * 0] = temp;
    }
}
