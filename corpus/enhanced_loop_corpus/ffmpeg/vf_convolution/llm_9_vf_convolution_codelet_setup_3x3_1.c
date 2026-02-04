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
// Unroll the loop completely to increase computational intensity and eliminate loop overhead
int xoff, yoff;

// i = 0
xoff = ((x + (-1)) >= 0 ? (x - 1) : (-(x - 1)));
yoff = ((y + (-1)) >= 0 ? (y - 1) : (-(y - 1)));
xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
yoff = yoff >= h ? 2 * h - 1 - yoff : yoff;
c[0] = src + xoff * bpc + yoff * stride;

// i = 1
xoff = (x >= 0 ? x : -x);
yoff = ((y + (-1)) >= 0 ? (y - 1) : (-(y - 1)));
xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
yoff = yoff >= h ? 2 * h - 1 - yoff : yoff;
c[1] = src + xoff * bpc + yoff * stride;

// i = 2
xoff = ((x + 1) >= 0 ? (x + 1) : (-(x + 1)));
yoff = ((y + (-1)) >= 0 ? (y - 1) : (-(y - 1)));
xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
yoff = yoff >= h ? 2 * h - 1 - yoff : yoff;
c[2] = src + xoff * bpc + yoff * stride;

// i = 3
xoff = ((x + (-1)) >= 0 ? (x - 1) : (-(x - 1)));
yoff = (y >= 0 ? y : -y);
xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
yoff = yoff >= h ? 2 * h - 1 - yoff : yoff;
c[3] = src + xoff * bpc + yoff * stride;

// i = 4
xoff = (x >= 0 ? x : -x);
yoff = (y >= 0 ? y : -y);
xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
yoff = yoff >= h ? 2 * h - 1 - yoff : yoff;
c[4] = src + xoff * bpc + yoff * stride;

// i = 5
xoff = ((x + 1) >= 0 ? (x + 1) : (-(x + 1)));
yoff = (y >= 0 ? y : -y);
xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
yoff = yoff >= h ? 2 * h - 1 - yoff : yoff;
c[5] = src + xoff * bpc + yoff * stride;

// i = 6
xoff = ((x + (-1)) >= 0 ? (x - 1) : (-(x - 1)));
yoff = ((y + 1) >= 0 ? (y + 1) : (-(y + 1)));
xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
yoff = yoff >= h ? 2 * h - 1 - yoff : yoff;
c[6] = src + xoff * bpc + yoff * stride;

// i = 7
xoff = (x >= 0 ? x : -x);
yoff = ((y + 1) >= 0 ? (y + 1) : (-(y + 1)));
xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
yoff = yoff >= h ? 2 * h - 1 - yoff : yoff;
c[7] = src + xoff * bpc + yoff * stride;

// i = 8
xoff = ((x + 1) >= 0 ? (x + 1) : (-(x + 1)));
yoff = ((y + 1) >= 0 ? (y + 1) : (-(y + 1)));
xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
yoff = yoff >= h ? 2 * h - 1 - yoff : yoff;
c[8] = src + xoff * bpc + yoff * stride;
}
