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
    int x_idx = i % 7;
    int y_idx = i / 7;
    int xoff = (x + x_idx - 3);
    int yoff = (y + y_idx - 3);

    // Reflective boundary handling using absolute value and clamp
    xoff = (xoff < 0) ? -xoff : xoff;
    yoff = (yoff < 0) ? -yoff : yoff;
    xoff = (xoff >= w) ? 2 * w - 1 - xoff : xoff;
    yoff = (yoff >= h) ? 2 * h - 1 - yoff : yoff;

    // Consecutive memory access pattern: reorder c[] to group by spatial proximity
    // Map 7x7 kernel indices into a scan-line order to improve spatial locality in c[]
    int linear_idx = y_idx * 7 + x_idx; // Now accessing c in row-major order
    c[linear_idx] = src + xoff * bpc + yoff * stride;
}
}
