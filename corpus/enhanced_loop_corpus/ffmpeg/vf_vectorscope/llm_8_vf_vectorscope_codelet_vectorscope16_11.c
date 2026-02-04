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
for (i = 0; i < h; i += 2) {
    const int iw1_base = i * slinesizex;
    const int iw2_base = i * slinesizey;
    const int iwd_base = i * slinesized;
    for (j = 0; j < w; j += 2) {
        const int idx1 = iw1_base + j;
        const int idx2 = iw2_base + j;
        const int idxd = iwd_base + j;
        const int x = spx[idx1] > max ? max : spx[idx1];
        const int y = spy[idx2] > max ? max : spy[idx2];
        const int z = spd[idxd];
        const int pos = y * dlinesize + x;
        if (z >= tmin && z <= tmax) {
            const int new_intensity = dpd[pos] + intensity;
            dpd[pos] = new_intensity > max ? max : new_intensity;
            dpx[pos] = x;
            dpy[pos] = y;
        }
    }
}
}
