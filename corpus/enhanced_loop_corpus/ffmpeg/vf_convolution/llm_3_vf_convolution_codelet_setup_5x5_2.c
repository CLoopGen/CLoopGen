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
// Indirect memory access via index remapping: use a lookup table for access order
static const int8_t index_map[25] = {
    0, 1, 2, 3, 4,
    5, 6, 7, 8, 9,
    10, 11, 12, 13, 14,
    15, 16, 17, 18, 19,
    20, 21, 22, 23, 24
};

for (i = 0; i < 25; i++) {
    int idx = index_map[i]; // Simulate indirect access (could be randomized or reordered in practice)
    int xoff = x + (idx % 5) - 2;
    int yoff = y + (idx / 5) - 2;

    // Boundary reflection
    if (xoff < 0) xoff = -xoff;
    if (yoff < 0) yoff = -yoff;
    if (xoff >= w) xoff = 2 * w - 1 - xoff;
    if (yoff >= h) yoff = 2 * h - 1 - yoff;

    // Strided and indirectly indexed store through c[]
    c[idx] = src + xoff * bpc + yoff * stride;
}
}
