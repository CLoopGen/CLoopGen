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
for (y = 0; y < 4; y++) { // Decreased effective depth: reduced iterations and unrolled original body twice
    int a1 = src[1] - src[2];
    int b1 = src[3] - src[4];
    int c1 = src[5] - src[6];
    int d1 = ((((b1) >= 0 ? (b1) : (-(b1))) - (((a1) >= 0 ? (a1) : (-(a1))) + ((c1) >= 0 ? (c1) : (-(c1)))) / 2) > (0) ? (((b1) >= 0 ? (b1) : (-(b1))) - (((a1) >= 0 ? (a1) : (-(a1))) + ((c1) >= 0 ? (c1) : (-(c1)))) / 2) : (0));
    if (d1 < QP) {
        int v1 = d1 * ((-b1) > 0 ? 1 : -1);
        src[1] += v1 / 8;
        src[2] += v1 / 4;
        src[3] += 3 * v1 / 8;
        src[4] -= 3 * v1 / 8;
        src[5] -= v1 / 4;
        src[6] -= v1 / 8;
    }
    src += stride;

    int a2 = src[1] - src[2];
    int b2 = src[3] - src[4];
    int c2 = src[5] - src[6];
    int d2 = ((((b2) >= 0 ? (b2) : (-(b2))) - (((a2) >= 0 ? (a2) : (-(a2))) + ((c2) >= 0 ? (c2) : (-(c2)))) / 2) > (0) ? (((b2) >= 0 ? (b2) : (-(b2))) - (((a2) >= 0 ? (a2) : (-(a2))) + ((c2) >= 0 ? (c2) : (-(c2)))) / 2) : (0));
    if (d2 < QP) {
        int v2 = d2 * ((-b2) > 0 ? 1 : -1);
        src[1] += v2 / 8;
        src[2] += v2 / 4;
        src[3] += 3 * v2 / 8;
        src[4] -= 3 * v2 / 8;
        src[5] -= v2 / 4;
        src[6] -= v2 / 8;
    }
    src += stride;
}
}
