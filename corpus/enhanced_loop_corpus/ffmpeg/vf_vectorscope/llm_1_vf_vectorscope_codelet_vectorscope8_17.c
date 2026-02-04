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
for (i = 0; i < h * w; i++) {
    const int j = i % w;
    const int i_val = i / w;
    const int iw1 = i_val * slinesizex;
    const int iw2 = i_val * slinesizey;
    const int iwd = i_val * slinesized;
    const int x = spx[iw1 + j];
    const int y = spy[iw2 + j];
    const int z = spd[iwd + j];
    const int pos = y * dlinesize + x;
    if (z < tmin || z > tmax)
        continue;
    if (!dpd[pos])
        dpd[pos] = ((128 - x) >= 0 ? (128 - x) : (-(128 - x))) + ((128 - y) >= 0 ? (128 - y) : (-(128 - y)));
    dpx[pos] = x;
    dpy[pos] = y;
}
}
