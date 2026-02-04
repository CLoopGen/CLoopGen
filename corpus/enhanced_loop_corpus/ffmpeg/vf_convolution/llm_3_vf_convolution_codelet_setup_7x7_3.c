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
// Indirect memory access via index array to enable flexible or reordered access
static const int index_map[49] = {
    0, 13, 26, 39, 1, 14, 27, 40, 2, 15, 28, 41, 3, 16, 29, 42,
    4, 17, 30, 43, 5, 18, 31, 44, 6, 19, 32, 45, 7, 20, 33, 46,
    8, 21, 34, 47, 9, 22, 35, 48, 10, 23, 36, 11, 24, 37, 12, 25, 38
}; // Example permutation to simulate non-sequential access

for (i = 0; i < 49; i++) {
    int raw_i = index_map[i]; // Indirect indexing
    int xi = raw_i % 7;
    int yi = raw_i / 7;
    int xoff = x + xi - 3;
    int yoff = y + yi - 3;

    // Boundary reflection
    xoff = xoff < 0 ? -xoff : xoff;
    yoff = yoff < 0 ? -yoff : yoff;
    xoff = xoff >= w ? 2*w - 1 - xoff : xoff;
    yoff = yoff >= h ? 2*h - 1 - yoff : yoff;

    // Strided but indirectly indexed store
    c[raw_i] = src + xoff * bpc + yoff * stride;
}
}
