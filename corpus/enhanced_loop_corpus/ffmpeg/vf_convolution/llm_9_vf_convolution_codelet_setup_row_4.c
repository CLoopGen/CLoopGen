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
int limit = radius * 2 + 1;
for (i = 0; i < limit; i++) {
    int offset = x + i - radius;
    int xoff = offset;
    if (offset < 0) xoff = -offset;
    if (xoff >= w) xoff = 2 * w - 1 - xoff;
    uint8_t* base_src = src + y * stride;
    c[i] = base_src + xoff * bpc;
}
}
