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
for (i = 0; i < h; i++) {
    const int iw1 = i * slinesizex;
    const int iw2 = i * slinesizey;
    const int iwd = i * slinesized;
    int threshold_center = (tmin + tmax) / 2;
    for (j = 0; j < w; j++) {
        const int x = spx[iw1 + j];
        const int y = spy[iw2 + j];
        const int z = spd[iwd + j];
        if (z < tmin || z > tmax)
            continue;
        const int pos = y * dlinesize + x;
        if (z <= threshold_center) {
            if (!dpd[pos]) {
                int dist_x = 128 - x;
                int dist_y = 128 - y;
                dpd[pos] = (dist_x >= 0 ? dist_x : -dist_x) + (dist_y >= 0 ? dist_y : -dist_y);
            }
        } else {
            int weighted_val = (x * 3 + y * 2) % 256;
            if (!dpd[pos] || dpd[pos] > weighted_val) {
                dpx[pos] = x;
                dpy[pos] = y;
                dpd[pos] = weighted_val;
            }
            continue;
        }
        dpx[pos] = x;
        dpy[pos] = y;
    }
}
}
