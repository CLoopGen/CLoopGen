#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *c[];
extern  uint8_t *src;
extern int stride;
extern int x;
extern int w;
extern int y;
extern int h;
extern int bpc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int idx = 0;
for (int yi = 0; yi < 7; yi++) {
    for (int xi = 0; xi < 7; xi++, idx++) {
        int xoff = ((x + (xi - 3)) >= 0 ? (x + (xi - 3)) : (-(x + (xi - 3))));
        int yoff = ((y + yi - 3) >= 0 ? (y + yi - 3) : (-(y + yi - 3)));
        xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
        yoff = yoff >= h ? 2 * h - 1 - yoff : yoff;
        c[idx] = src + xoff * bpc + yoff * stride;
    }
}
}
