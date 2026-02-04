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
for (y = 0; y < 8; y += 2) {
    for (x = 0; x < 8; x += 2) {
        int idx = (x/2) * 4 + (y/2) * stride;
        int val_r = block[idx + 0];
        int val_g = block[idx + 1];
        int val_b = block[idx + 2];
        int dot = val_r * v_r + val_g * v_g + val_b * v_b;
        if (dot < mind) {
            mind = dot;
            minp = block + idx;
        }
        if (dot > maxd) {
            maxd = dot;
            maxp = block + idx;
        }
    }
}
}
