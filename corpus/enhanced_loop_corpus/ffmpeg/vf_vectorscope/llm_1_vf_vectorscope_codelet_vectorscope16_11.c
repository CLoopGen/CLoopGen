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
for (i = 0; i < h * w; i++) {
    const int j = i % w;
    const int i_row = i / w;
    const int iw1 = i_row * slinesizex;
    const int iw2 = i_row * slinesizey;
    const int iwd = i_row * slinesized;
    const int x = ((spx[iw1 + j]) > (max) ? (max) : (spx[iw1 + j]));
    const int y = ((spy[iw2 + j]) > (max) ? (max) : (spy[iw2 + j]));
    const int z = spd[iwd + j];
    const int pos = y * dlinesize + x;
    if (z < tmin || z > tmax)
        continue;
    dpd[pos] = ((max) > (dpd[pos] + intensity) ? (dpd[pos] + intensity) : (max));
    dpx[pos] = x;
    dpy[pos] = y;
}
}
