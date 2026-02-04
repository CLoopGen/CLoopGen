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
extern  int mid;
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
    uint16_t *spx_base = spx + iw1;
    uint16_t *spy_base = spy + iw2;
    uint16_t *spd_base = spd + iwd;
    for (j = 0; j < w; j++) {
        const int idx = j;
        const int x = ((spx_base[idx]) > (max) ? (max) : (spx_base[idx]));
        const int y = ((spy_base[idx]) > (max) ? (max) : (spy_base[idx]));
        const int z = spd_base[idx];
        const int pos = y * dlinesize + x;
        if (z < tmin || z > tmax)
            continue;
        if (!dpd[pos])
            dpd[pos] = ((mid - x) >= 0 ? (mid - x) : (-(mid - x))) + ((mid - y) >= 0 ? (mid - y) : (-(mid - y)));
        dpx[pos] = x;
        dpy[pos] = y;
    }
}
}
