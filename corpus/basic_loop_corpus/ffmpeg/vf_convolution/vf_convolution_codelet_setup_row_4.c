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
for (i = 0; i < radius * 2 + 1; i++) {
    int xoff = ((x + i - radius) >= 0 ? (x + i - radius) : (-(x + i - radius)));
    xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
    c[i] = src + xoff * bpc + y * stride;
}

}
