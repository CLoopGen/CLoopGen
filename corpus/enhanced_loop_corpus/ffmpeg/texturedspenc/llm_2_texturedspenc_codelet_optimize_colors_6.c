#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern  uint8_t *minp;
extern  uint8_t *maxp;
extern int v_r;
extern int v_g;
extern int v_b;
extern int mind;
extern int maxd;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed base pointer and offset strides
    uint8_t *base = block;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            uint8_t *pixel = base + x * 4 + y * stride;
            int dot = pixel[0] * v_r + pixel[1] * v_g + pixel[2] * v_b;
            if (dot < mind) {
                mind = dot;
                minp = pixel;
            } else if (dot > maxd) {
                maxd = dot;
                maxp = pixel;
            }
        }
    }
}
