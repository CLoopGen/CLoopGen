#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int w;
extern int i;
extern int r;
extern int g;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ((w) > (32) ? (32) : (w)); i += 2) {
    const int rt1 = src[i * 3 + 0];
    const int gt1 = src[i * 3 + 1];
    const int bt1 = src[i * 3 + 2];
    dst[i * 3 + 0] = rt1 - r;
    dst[i * 3 + 1] = gt1 - g;
    dst[i * 3 + 2] = bt1 - b;
    r = rt1;
    g = gt1;
    b = bt1;

    if (i + 1 < w) {
        const int rt2 = src[(i + 1) * 3 + 0];
        const int gt2 = src[(i + 1) * 3 + 1];
        const int bt2 = src[(i + 1) * 3 + 2];
        dst[(i + 1) * 3 + 0] = rt2 - r;
        dst[(i + 1) * 3 + 1] = gt2 - g;
        dst[(i + 1) * 3 + 2] = bt2 - b;
        r = rt2;
        g = gt2;
        b = bt2;
    }
}
}
