#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int slinesizex;
extern  int slinesizey;
extern  int slinesized;
extern  int dlinesize;
extern  int h;
extern  int w;
extern  uint8_t *spx;
extern  uint8_t *spy;
extern  uint8_t *spd;
extern uint8_t *dpx;
extern uint8_t *dpy;
extern uint8_t *dpd;
extern  int tmin;
extern  int tmax;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    for (j = 0; j < w; j++) {
        const int indices[4] = {
            i * slinesizex + j,
            i * slinesizey + j,
            i * slinesized + j,
            (i + 1) * slinesizex + j
        };
        const int x = spx[indices[0]];
        const int y = spy[indices[1]];
        const int z = spd[indices[2]];
        const int pos = y * dlinesize + x;
        if (z >= tmin && z <= tmax) {
            const int sum = x + y;
            if (!dpd[pos])
                dpd[pos] = sum > 255 ? 255 : sum;
            dpx[pos] = x;
            dpy[pos] = y;
        }
        if (i + 1 < h) {
            const int x2 = spx[indices[3]];
            const int y2 = spy[(i + 1) * slinesizey + j];
            const int z2 = spd[(i + 1) * slinesized + j];
            const int pos2 = y2 * dlinesize + x2;
            if (z2 >= tmin && z2 <= tmax) {
                const int sum2 = x2 + y2;
                if (!dpd[pos2])
                    dpd[pos2] = sum2 > 255 ? 255 : sum2;
                dpx[pos2] = x2;
                dpy[pos2] = y2;
            }
        }
    }
}
}
