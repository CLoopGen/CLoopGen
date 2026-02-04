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
    for (x = 2; x < size; x += 2) {
        int temp1 = top[x] + dc;
        int temp2 = top[x-1] + dc;
        src[(x) + stride * (0)] = (temp1 + 2 * dc + 2) >> 2;
        src[(x-1) + stride * (0)] = (temp2 + 2 * dc + 2) >> 2;
    }
}
