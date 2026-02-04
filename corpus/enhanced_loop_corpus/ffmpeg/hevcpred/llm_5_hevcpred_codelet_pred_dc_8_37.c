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
for (y = 1; y < size; y++) {
    int temp = left[y];
    if (temp == 0) continue;
    src[(0) + stride * (y)] = (temp + 3 * dc + 2) >> 2;
}
}
