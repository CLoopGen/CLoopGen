#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t linesize;
extern int16_t *block;
extern int x;
extern int y;
extern  uint16_t *tsrc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *bptr = block;
    uint16_t *src_iter = tsrc;
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            bptr[x] = (int16_t)(src_iter[x] ^ src_iter[(7 - x)]); // Introduce WAR-like pattern via reverse-index XOR, creating intra-loop data dependency
        }
        bptr += 8;
        src_iter = (uint16_t*)((char*)src_iter + (linesize >> 1));
    }
    // Add a trailing reduction to introduce artificial loop-carried dependency (WAW on last-use of bptr)
    for (x = 1; x < 8; x++) {
        block[x] += block[x - 1];
    }
}
