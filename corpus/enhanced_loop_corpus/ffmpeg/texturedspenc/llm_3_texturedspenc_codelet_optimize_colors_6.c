#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern  uint8_t *minp;
extern  uint8_t *maxp;
extern int v_r;
extern int v_g;
extern int v_b;
extern int mind;
extern int maxd;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access along the y-axis first, then x-axis (transpose-like traversal)
    // This changes the access pattern from row-major to column-major in terms of logical iteration
    for (x = 0; x < 4; x++) {
        for (y = 0; y < 4; y++) {
            int offset = x * 4 + y * stride;
            int dot = block[offset + 0] * v_r + block[offset + 1] * v_g + block[offset + 2] * v_b;
            if (dot < mind) {
                mind = dot;
                minp = block + offset;
            } else if (dot > maxd) {
                maxd = dot;
                maxp = block + offset;
            }
        }
    }
}
