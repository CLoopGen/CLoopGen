#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int y;
extern int size;
extern uint16_t *src;
extern  uint16_t *left;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int factor = dc * 3;
    for (y = 1; y < size - 1; y++) {
        uint16_t temp = left[y] + factor;
        src[stride * y] = (temp + temp + temp + temp + 8) >> 3;
    }
}
