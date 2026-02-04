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
    int offset = y * stride;
    int a = src[offset + 1] - src[offset + 2];
    int b = src[offset + 3] - src[offset + 4];
    int c = src[offset + 5] - src[offset + 6];
    int d = ((((b) >= 0 ? (b) : (-(b))) - (((a) >= 0 ? (a) : (-(a))) + ((c) >= 0 ? (c) : (-(c)))) / 2) > (0) ? (((b) >= 0 ? (b) : (-(b))) - (((a) >= 0 ? (a) : (-(a))) + ((c) >= 0 ? (c) : (-(c)))) / 2) : (0));
    if (d < QP) {
        int v = d * ((-b) > 0 ? 1 : -1);
        src[offset + 1] += v / 8;
        src[offset + 2] += v / 4;
        src[offset + 3] += 3 * v / 8;
        src[offset + 4] -= 3 * v / 8;
        src[offset + 5] -= v / 4;
        src[offset + 6] -= v / 8;
    }
}
}
