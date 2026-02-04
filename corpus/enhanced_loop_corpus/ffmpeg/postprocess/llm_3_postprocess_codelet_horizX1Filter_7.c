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
const int indices[] = {1, 2, 3, 4, 5, 6};
for (y = 0; y < 8; y++) {
    int base = y * stride;
    int a = src[base + indices[0]] - src[base + indices[1]];
    int b = src[base + indices[2]] - src[base + indices[3]];
    int c = src[base + indices[4]] - src[base + indices[5]];
    int abs_a = (a >= 0) ? a : -a;
    int abs_c = (c >= 0) ? c : -c;
    int abs_b = (b >= 0) ? b : -b;
    int diff = abs_b - (abs_a + abs_c) / 2;
    int d = (diff > 0) ? diff : 0;
    if (d < QP) {
        int sign = (-b) > 0 ? 1 : -1;
        int v = d * sign;
        src[base + indices[0]] += v / 8;
        src[base + indices[1]] += v / 4;
        src[base + indices[2]] += 3 * v / 8;
        src[base + indices[3]] -= 3 * v / 8;
        src[base + indices[4]] -= v / 4;
        src[base + indices[5]] -= v / 8;
    }
}
}
