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
for (i = 0; i < h; i++) {
    const int iw1 = i * slinesizex;
    const int iw2 = i * slinesizey;
    const int iwd = i * slinesized;
    int prev_pos = -1;
    int prev_x = 0, prev_y = 0;
    for (j = 0; j < w; j++) {
        const int x = spx[iw1 + j];
        const int y = spy[iw2 + j];
        const int z = spd[iwd + j];
        const int pos = y * dlinesize + x;
        if (z < tmin || z > tmax)
            continue;
        // Introduce RAW and loop-carried dependency: current update depends on previous iteration's pos
        if (prev_pos != -1 && prev_pos < pos) {
            dpd[prev_pos] = (dpd[prev_pos] < 128) ? (dpd[prev_pos] + 10) : dpd[prev_pos];
            dpx[prev_pos] = prev_x;
            dpy[prev_pos] = prev_y;
        }
        dpd[pos] = ((255) > (dpd[pos] + intensity) ? (dpd[pos] + intensity) : (255));
        dpx[pos] = x;
        dpy[pos] = y;
        // Carry state to next iteration
        prev_pos = pos;
        prev_x = x;
        prev_y = y;
    }
    // Finalize last element if needed (optional side-effect, but maintains consistency)
    if (prev_pos != -1) {
        dpd[prev_pos] = (dpd[prev_pos] + 1) > 255 ? 255 : dpd[prev_pos] + 1;
    }
}
}
