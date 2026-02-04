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
    int a = src[1] - src[2];
    int b = src[3] - src[4];
    int c = src[5] - src[6];
    int abs_a = (a >= 0) ? a : -a;
    int abs_c = (c >= 0) ? c : -c;
    int temp = (abs_a + abs_c) / 2;
    int abs_b = (b >= 0) ? b : -b;
    int d = (abs_b - temp > 0) ? (abs_b - temp) : 0;
    if (d < QP) {
        int sign = (b < 0) ? 1 : -1;
        int v = d * sign;
        src[1] = src[1] + v / 8;
        src[2] = src[2] + v / 4;
        src[3] = src[3] + 3 * v / 8;
        src[4] = src[4] - 3 * v / 8;
        src[5] = src[5] - v / 4;
        src[6] = src[6] - v / 8;
    }
    src += stride;
}
}
