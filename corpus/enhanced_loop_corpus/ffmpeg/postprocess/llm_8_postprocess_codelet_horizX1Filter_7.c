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
for (y = 0; y < 16; y += 2) {
    int a = src[1] - src[2];
    int b = src[3] - src[4];
    int c = src[5] - src[6];
    int abs_a = (a >= 0) ? a : -a;
    int abs_c = (c >= 0) ? c : -c;
    int diff = (b >= 0) ? b : -b;
    int threshold = (abs_a + abs_c) / 2;
    int d = (diff > threshold) ? (diff - threshold) : 0;
    if (d < QP) {
        int sign = (b < 0) ? 1 : -1;
        int v = d * sign;
        src[1] += v / 8;
        src[2] += v / 4;
        src[3] += 3 * v / 8;
        src[4] -= 3 * v / 8;
        src[5] -= v / 4;
        src[6] -= v / 8;
    }
    src += stride;
}
}
