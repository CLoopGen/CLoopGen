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
for (i = 0; i < h; i++) {
    const int iw1 = i * slinesizex;
    const int iw2 = i * slinesizey;
    const int iwd = i * slinesized;
    int prev_x = 0, prev_y = 0;
    for (j = 0; j < w; j++) {
        const int raw_x = spx[iw1 + j];
        const int raw_y = spy[iw2 + j];
        const int x = (raw_x > max) ? max : raw_x;
        const int y = (raw_y > max) ? max : raw_y;
        const int z = spd[iwd + j];
        
        const int smoothed_x = (prev_x + x) / 2;
        const int smoothed_y = (prev_y + y) / 2;
        prev_x = smoothed_x;
        prev_y = smoothed_y;

        const int pos = smoothed_y * dlinesize + smoothed_x;
        if (z < tmin || z > tmax)
            continue;
        if (!dpd[pos])
            dpd[pos] = ((smoothed_x + smoothed_y) > max) ? max : (smoothed_x + smoothed_y);
        dpx[pos] = smoothed_x;
        dpy[pos] = smoothed_y;
    }
}
}
