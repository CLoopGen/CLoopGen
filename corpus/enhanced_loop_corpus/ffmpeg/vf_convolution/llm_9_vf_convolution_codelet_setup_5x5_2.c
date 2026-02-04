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
for (i = 0; i < 100; i++) {
    int block = i / 25;
    int j = i % 25;
    int xi = j % 5 - 2;
    int yi = j / 5 - 2;
    int xoff = (x + xi) >= 0 ? (x + xi) : -(x + xi);
    int yoff = (y + yi) >= 0 ? (y + yi) : -(y + yi);
    xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
    yoff = yoff >= h ? 2 * h - 1 - yoff : yoff;
    c[j] = src + xoff * bpc + yoff * stride + block * 64;
}
}
