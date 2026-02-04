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
    for (y = 0; y < 2; y++) {
        for (x = 0; x < 2; x++) {
            int dot1 = block[x * 4 + y * stride + 0] * v_r + block[x * 4 + y * stride + 1] * v_g + block[x * 4 + y * stride + 2] * v_b;
            int dot2 = block[(x+2) * 4 + y * stride + 0] * v_r + block[(x+2) * 4 + y * stride + 1] * v_g + block[(x+2) * 4 + y * stride + 2] * v_b;
            int dot3 = block[x * 4 + (y+2) * stride + 0] * v_r + block[x * 4 + (y+2) * stride + 1] * v_g + block[x * 4 + (y+2) * stride + 2] * v_b;
            int dot4 = block[(x+2) * 4 + (y+2) * stride + 0] * v_r + block[(x+2) * 4 + (y+2) * stride + 1] * v_g + block[(x+2) * 4 + (y+2) * stride + 2] * v_b;

            if (dot1 < mind) {
                mind = dot1;
                minp = block + x * 4 + y * stride;
            } else if (dot1 > maxd) {
                maxd = dot1;
                maxp = block + x * 4 + y * stride;
            }

            if (dot2 < mind) {
                mind = dot2;
                minp = block + (x+2) * 4 + y * stride;
            } else if (dot2 > maxd) {
                maxd = dot2;
                maxp = block + (x+2) * 4 + y * stride;
            }

            if (dot3 < mind) {
                mind = dot3;
                minp = block + x * 4 + (y+2) * stride;
            } else if (dot3 > maxd) {
                maxd = dot3;
                maxp = block + x * 4 + (y+2) * stride;
            }

            if (dot4 < mind) {
                mind = dot4;
                minp = block + (x+2) * 4 + (y+2) * stride;
            } else if (dot4 > maxd) {
                maxd = dot4;
                maxp = block + (x+2) * 4 + (y+2) * stride;
            }
        }
    }
}
