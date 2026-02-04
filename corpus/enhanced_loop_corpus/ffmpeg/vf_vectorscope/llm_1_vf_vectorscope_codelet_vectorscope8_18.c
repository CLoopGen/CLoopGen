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
    int j_batch = 0;
    for (; j_batch < w - 3; j_batch += 4) {
        for (int k = 0; k < 4; k++) {
            const int j = j_batch + k;
            const int x = spx[iw1 + j];
            const int y = spy[iw2 + j];
            const int z = spd[iwd + j];
            const int pos = y * dlinesize + x;
            if (z < tmin || z > tmax)
                continue;
            if (!dpd[pos])
                dpd[pos] = ((x + y) > 255 ? 255 : (x + y));
            dpx[pos] = x;
            dpy[pos] = y;
        }
    }
    for (; j_batch < w; j_batch++) {
        const int x = spx[iw1 + j_batch];
        const int y = spy[iw2 + j_batch];
        const int z = spd[iwd + j_batch];
        const int pos = y * dlinesize + x;
        if (z < tmin || z > tmax)
            continue;
        if (!dpd[pos])
            dpd[pos] = ((x + y) > 255 ? 255 : (x + y));
        dpx[pos] = x;
        dpy[pos] = y;
    }
}
}
