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
for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
        int dot = block[x * 4 + y * stride + 0] * v_r + block[x * 4 + y * stride + 1] * v_g + block[x * 4 + y * stride + 2] * v_b;
        mind = (dot < mind) ? dot : mind;
        maxd = (dot > maxd) ? dot : maxd;
        minp = (dot < mind) ? block + x * 4 + y * stride : minp;
        maxp = (dot > maxd) ? block + x * 4 + y * stride : maxp;
    }
}
}
