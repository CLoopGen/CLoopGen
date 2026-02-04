#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t sstride;
extern int h;
extern int a;
extern int b;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling
    uint8_t *src_local = src;
    uint8_t *tmp_local = tmp;
    for (y = 0; y < h + 1; y++) {
        const uint8_t *s = src_local;
        uint8_t *t = tmp_local;
        // Unroll the inner loop partially for consecutive access pattern
        for (x = 0; x < 16; x += 4) {
            t[x+0] = (a * s[x+0] + b * s[x+1] + 4) >> 3;
            t[x+1] = (a * s[x+1] + b * s[x+2] + 4) >> 3;
            t[x+2] = (a * s[x+2] + b * s[x+3] + 4) >> 3;
            t[x+3] = (a * s[x+3] + b * s[x+4] + 4) >> 3;
        }
        tmp_local += 16;
        src_local += sstride;
    }
}
