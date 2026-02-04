#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int radius;
extern  uint8_t *c[];
extern  uint8_t *src;
extern int stride;
extern int x;
extern int y;
extern int h;
extern int bpc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t **temp_c = c;  // Introduce pointer alias to modify write access pattern
    int r = radius;        // Local copy of radius to break direct dependency in condition
    int r2p1 = r * 2 + 1;  // Precompute loop bound to remove recurrence from induction variable
    int y_bpc = y * bpc;   // Hoist invariant expression to reduce address computation inside loop

    for (i = 0; i < r2p1; i++) {
        int idx = i - r;
        int xoff = x + idx;
        if (xoff < 0) xoff = -xoff;         // Reflect negative indices
        if (xoff >= h) xoff = 2 * h - 1 - xoff; // Mirror at boundary
        c[i] = src + y_bpc + xoff * stride; // Use hoisted and computed offsets
    }
}
