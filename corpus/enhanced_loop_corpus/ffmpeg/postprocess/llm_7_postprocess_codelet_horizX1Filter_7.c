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
int prev_v = 0;
for (y = 0; y < 8; y++) {
    int offset = y * stride;
    int a = src[offset + 1] - src[offset + 2];
    int b = src[offset + 3] - src[offset + 4];
    int c = src[offset + 5] - src[offset + 6];
    int abs_a = (a >= 0) ? a : -a;
    int abs_b = (b >= 0) ? b : -b;
    int abs_c = (c >= 0) ? c : -c;
    int diff = abs_b - ((abs_a + abs_c) / 2);
    int d = (diff > 0) ? diff : 0;
    if (d < QP) {
        int sign = (b > 0) ? -1 : 1;
        int v = d * sign + prev_v / 2;
        src[offset + 1] += v / 8;
        src[offset + 2] += v / 4;
        src[offset + 3] += 3 * v / 8;
        src[offset + 4] -= 3 * v / 8;
        src[offset + 5] -= v / 4;
        src[offset + 6] -= v / 8;
        prev_v = v;
    } else {
        prev_v = 0;
    }
}
}
