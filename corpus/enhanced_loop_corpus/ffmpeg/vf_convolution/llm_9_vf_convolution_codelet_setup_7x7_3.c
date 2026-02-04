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
for (i = 0; i < 98; i += 2) {
    int xi = i % 14;
    int yi = i / 14;
    int local_xoff = (x + (xi - 3)) >= 0 ? (x + (xi - 3)) : (-(x + (xi - 3)));
    int local_yoff = (y + (yi - 3)) >= 0 ? (y + (yi - 3)) : (-(y + (yi - 3)));
    local_xoff = local_xoff >= w ? 2 * w - 1 - local_xoff : local_xoff;
    local_yoff = local_yoff >= h ? 2 * h - 1 - local_yoff : local_yoff;
    uint8_t* temp_ptr = src + local_xoff * bpc + local_yoff * stride;
    c[i/2] = temp_ptr;
}
}
