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
for (j = 0; j < w; j++) {
    for (i = 0; i < h; i++) {
        const int idx_src = i * slinesizex + j;
        const int x = spx[idx_src];
        const int y = spy[i * slinesizey + j];
        const int z = spd[i * slinesized + j];
        const int pos = y * dlinesize + x;
        if (z < tmin || z > tmax)
            continue;
        uint8_t new_intensity = (dpd[pos] + intensity > 255) ? 255 : dpd[pos] + intensity;
        dpd[pos] = new_intensity;
        dpx[pos] = x;
        dpy[pos] = y;
    }
}
}
