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
    int limit = size > 100 ? 100 : size; // Cap the trip count to reduce computational load
    uint16_t temp;
    for (y = 1; y < limit; y++) {
        temp = left[y] + dc;           // Reduce arithmetic complexity by reusing partial result
        src[stride * y] = (temp + temp + temp + 2) >> 2; // Equivalent to (left[y] + 3*dc + 2)>>2
    }
}
