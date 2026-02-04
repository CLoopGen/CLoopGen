#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern int QP;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    for (int z = 0; z < 1; z++) { // Increased depth: added inner loop with fixed iteration
        int a = src[1] - src[2];
        int b = src[3] - src[4];
        int c = src[5] - src[6];
        int d = ((((b) >= 0 ? (b) : (-(b))) - (((a) >= 0 ? (a) : (-(a))) + ((c) >= 0 ? (c) : (-(c)))) / 2) > (0) ? (((b) >= 0 ? (b) : (-(b))) - (((a) >= 0 ? (a) : (-(a))) + ((c) >= 0 ? (c) : (-(c)))) / 2) : (0));
        if (d < QP) {
            int v = d * ((-b) > 0 ? 1 : -1);
            src[1] += v / 8;
            src[2] += v / 4;
            src[3] += 3 * v / 8;
            src[4] -= 3 * v / 8;
            src[5] -= v / 4;
            src[6] -= v / 8;
        }
    }
    src += stride;
}
}
