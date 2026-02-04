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
for (i = 0; i < 49; i++) {
    int xi = i % 7;
    int yi = i / 7;
    int xoff = x + xi - 3;
    int yoff = y + yi - 3;
    if (xoff < 0) xoff = -xoff;
    if (yoff < 0) yoff = -yoff;
    if (xoff >= w) xoff = 2 * w - 1 - xoff;
    if (yoff >= h) yoff = 2 * h - 1 - yoff;
    c[i] = src + xoff * bpc + yoff * stride;
}
}
