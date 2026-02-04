#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int radius;
extern  uint8_t *c[];
extern  uint8_t *src;
extern int stride;
extern int x;
extern int y;
extern int h;
extern int bpc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < radius * 2 + 1; i++) {
    int xoff = x + i - radius;
    if (xoff < 0) {
        xoff = -xoff;
    }
    if (xoff >= h) {
        xoff = 2 * h - 1 - xoff;
    }
    c[i] = src + y * bpc + xoff * stride;
}
}
