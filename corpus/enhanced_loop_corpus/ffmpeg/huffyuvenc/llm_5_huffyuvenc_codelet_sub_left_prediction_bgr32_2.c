#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;
extern int min_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < min_width; i++) {
    const int rt = src[i * 4 + 2];
    const int gt = src[i * 4 + 1];
    const int bt = src[i * 4 + 0];
    const int at = src[i * 4 + 3];

    dst[i * 4 + 2] = (rt != r) ? rt - r : 0;
    dst[i * 4 + 1] = (gt != g) ? gt - g : 0;
    dst[i * 4 + 0] = (bt != b) ? bt - b : 0;
    dst[i * 4 + 3] = (at != a) ? at - a : 0;

    if (rt % 2 == 0) {
        r = rt;
    } else {
        r = rt - 1;
    }
    if (gt % 2 == 0) {
        g = gt;
    } else {
        g = gt - 1;
    }
    if (bt % 2 == 0) {
        b = bt;
    } else {
        b = bt - 1;
    }
    a = at;
}
}
