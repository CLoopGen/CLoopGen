#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int slinesizex;
extern  int slinesizey;
extern  int slinesized;
extern  int dlinesize;
extern  int intensity;
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
for (i = 0; i < h; i++) {
    const int iw1 = i * slinesizex;
    const int iw2 = i * slinesizey;
    const int iwd = i * slinesized;
    for (j = 0; j < w; j++) {
        const int idx_x = iw1 + j;
        const int idx_y = iw2 + j;
        const int idx_d = iwd + j;
        const int x = spx[idx_x] > max ? max : spx[idx_x];
        const int y = spy[idx_y] > max ? max : spy[idx_y];
        const int z = spd[idx_d];
        const int pos = y * dlinesize + x;
        if (z < tmin || z > tmax)
            continue;
        const int new_intensity = dpd[pos] + intensity;
        dpd[pos] = new_intensity > max ? max : new_intensity;
        dpx[pos] = x;
        dpy[pos] = y;
    }
}
}
