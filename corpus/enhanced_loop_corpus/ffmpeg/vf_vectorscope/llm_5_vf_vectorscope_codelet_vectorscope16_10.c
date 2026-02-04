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
    for (j = 0; j < w; j++) {
        const int raw_x = spx[iw1 + j];
        const int raw_y = spy[iw2 + j];
        const int raw_z = spd[iwd + j];
        const int x = raw_x > max ? max : raw_x;
        const int y = raw_y > max ? max : raw_y;
        const int z = raw_z;
        const int pos = y * dlinesize + x;

        const int in_threshold = (z >= tmin) & (z <= tmax);
        const int dpd_empty = !dpd[pos];

        // Eliminate branching using conditional updates via logical expressions
        dpd[pos] = (in_threshold && dpd_empty) ? (x + y > max ? max : x + y) : dpd[pos];
        dpx[pos] = in_threshold ? x : dpx[pos];
        dpy[pos] = in_threshold ? y : dpy[pos];
    }
}
}
