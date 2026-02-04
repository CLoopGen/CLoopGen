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
extern  uint16_t *spx;
extern  uint16_t *spy;
extern  uint16_t *spd;
extern uint16_t *dpx;
extern uint16_t *dpy;
extern uint16_t *dpd;
extern  int max;
extern  int tmin;
extern  int tmax;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    const int iw1_base = i * slinesizex;
    const int iw2_base = i * slinesizey;
    const int iwd_base = i * slinesized;
    for (j = 0; j < w; j += 2) {
        const int idx1 = iw1_base + j;
        const int idx2 = iw2_base + j;
        const int idxd = iwd_base + j;
        const int x1 = spx[idx1] > max ? max : spx[idx1];
        const int y1 = spy[idx2] > max ? max : spy[idx2];
        const int z1 = spd[idxd];
        const int pos1 = y1 * dlinesize + x1;

        if (!(z1 < tmin || z1 > tmax)) {
            if (!dpd[pos1])
                dpd[pos1] = (x1 + y1) > max ? max : (x1 + y1);
            dpx[pos1] = x1;
            dpy[pos1] = y1;
        }

        if (j + 1 < w) {
            const int x2 = spx[idx1 + 1] > max ? max : spx[idx1 + 1];
            const int y2 = spy[idx2 + 1] > max ? max : spy[idx2 + 1];
            const int z2 = spd[idxd + 1];
            const int pos2 = y2 * dlinesize + x2;

            if (!(z2 < tmin || z2 > tmax)) {
                if (!dpd[pos2])
                    dpd[pos2] = (x2 + y2) > max ? max : (x2 + y2);
                dpx[pos2] = x2;
                dpy[pos2] = y2;
            }
        }
    }
    if (i + 1 < h) {
        const int iw1_next = (i + 1) * slinesizex;
        const int iw2_next = (i + 1) * slinesizey;
        const int iwd_next = (i + 1) * slinesized;
        for (j = 0; j < w; j++) {
            const int x = spx[iw1_next + j] > max ? max : spx[iw1_next + j];
            const int y = spy[iw2_next + j] > max ? max : spy[iw2_next + j];
            const int z = spd[iwd_next + j];
            const int pos = y * dlinesize + x;
            if (z < tmin || z > tmax)
                continue;
            if (!dpd[pos])
                dpd[pos] = (x + y) > max ? max : (x + y);
            dpx[pos] = x;
            dpy[pos] = y;
        }
    }
}
}
