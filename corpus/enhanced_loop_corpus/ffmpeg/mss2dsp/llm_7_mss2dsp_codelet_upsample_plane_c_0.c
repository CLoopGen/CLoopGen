#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *plane;
extern ptrdiff_t plane_stride;
extern int w;
extern int h;
extern uint8_t *p;
extern uint8_t a;
extern uint8_t b;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = h - 1; j >= 0; j--) {
    p = plane + plane_stride * j;
    int k;
    for (k = 1; k < w; k++) {
        int src_idx = k >> 1;
        uint8_t val = p[src_idx];
        p[k] = val;
    }
    for (k = w - ((w - 1) & 1); k >= 2; k -= 2) {
        uint8_t a_val = p[k >> 1];
        uint8_t b_val = p[(k + 1) >> 1];
        p[k] = (a_val + 3 * b_val + 1) >> 2;
        p[k - 1] = (3 * a_val + b_val + 1) >> 2;
    }
}
}
