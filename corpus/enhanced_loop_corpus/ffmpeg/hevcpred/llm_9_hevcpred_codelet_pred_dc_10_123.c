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
    int limit = size > 10 ? 10 : size;
    for (y = 1; y < limit; y++) {
        uint16_t temp = left[y] + dc;
        temp += dc;
        temp += dc;
        temp += 2;
        src[stride * y] = temp >> 2;
    }
}
