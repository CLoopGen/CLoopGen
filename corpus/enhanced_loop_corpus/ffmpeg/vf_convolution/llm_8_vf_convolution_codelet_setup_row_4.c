#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int radius;
extern  uint8_t *c[];
extern  uint8_t *src;
extern int stride;
extern int x;
extern int w;
extern int y;
extern int bpc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < radius * 4 + 2; i += 2) {
    int idx = i - radius;
    int xoff = (x + idx) >= 0 ? (x + idx) : -(x + idx);
    xoff = (xoff >= w) ? (2 * w - 1 - xoff) : xoff;
    c[i/2] = src + xoff * bpc + y * stride;
}
}
