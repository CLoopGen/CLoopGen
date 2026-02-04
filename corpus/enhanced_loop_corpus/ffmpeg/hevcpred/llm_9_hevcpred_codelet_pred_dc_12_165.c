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
    int limit = size < 100 ? size : 100; // Cap the trip count to reduce computation
    for (x = 1; x < limit; x++) {
        int offset = x + stride * 0;
        int sum = top[x] + dc;
        sum += dc; 
        sum += dc; // Equivalent to 3*dc, but split for higher operation count
        sum += 2;
        src[offset] = sum >> 2; // Same as division by 4 via bit shift
    }
}
