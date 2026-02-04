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
for (y = 0; y < 4; y++) {
    for (int x = 0; x < 2; x++) {
        int idx = 1 + x;
        int a = src[idx] - src[idx + 1];
        int b = src[idx + 2] - src[idx + 3];
        int c = src[idx + 4] - src[idx + 5];
        int abs_a = (a >= 0) ? a : -a;
        int abs_b = (b >= 0) ? b : -b;
        int abs_c = (c >= 0) ? c : -c;
        int sum_ac = (abs_a + abs_c + 1) >> 1;
        int d = abs_b - sum_ac;
        if (d < 0) d = 0;
        if (d < QP) {
            int v = (b < 0) ? d : -d;
            src[idx]   += v / 8;
            src[idx+1] += v / 4;
            src[idx+2] += 3 * v / 8;
            src[idx+3] -= 3 * v / 8;
            src[idx+4] -= v / 4;
            src[idx+5] -= v / 8;
        }
    }
    src += stride;
}
}
