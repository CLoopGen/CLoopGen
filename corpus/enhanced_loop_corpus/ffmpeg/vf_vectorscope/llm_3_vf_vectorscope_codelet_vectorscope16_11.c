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
const int stride = 4; // Unroll factor for consecutive memory access simulation
for (i = 0; i < h; i++) {
    const int iw1 = i * slinesizex;
    const int iw2 = i * slinesizey;
    const int iwd = i * slinesized;
    for (j = 0; j < w; j += stride) {
        // Process multiple elements per iteration to promote consecutive access
        for (int k = 0; k < stride && (j + k) < w; k++) {
            const int offset = j + k;
            const int x = spx[iw1 + offset] > max ? max : spx[iw1 + offset];
            const int y = spy[iw2 + offset] > max ? max : spy[iw2 + offset];
            const int z = spd[iwd + offset];
            const int pos = y * dlinesize + x;
            if (z < tmin || z > tmax)
                continue;
            dpd[pos] = (dpd[pos] + intensity > max) ? max : dpd[pos] + intensity;
            dpx[pos] = x;
            dpy[pos] = y;
        }
    }
}
}
