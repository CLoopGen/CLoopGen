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
const int stride = 4; // Unroll factor
for (i = 0; i < h; i++) {
    const int iw1 = i * slinesizex;
    const int iw2 = i * slinesizey;
    const int iwd = i * slinesized;
    for (j = 0; j < w - stride + 1; j += stride) {
        // Process 4 elements per iteration with consecutive memory access
        const int idx_x[4] = {iw1 + j, iw1 + j+1, iw1 + j+2, iw1 + j+3};
        const int idx_y[4] = {iw2 + j, iw2 + j+1, iw2 + j+2, iw2 + j+3};
        const int idx_d[4] = {iwd + j, iwd + j+1, iwd + j+2, iwd + j+3};

        for (int k = 0; k < stride; k++) {
            const int x = spx[idx_x[k]] > max ? max : spx[idx_x[k]];
            const int y = spy[idx_y[k]] > max ? max : spy[idx_y[k]];
            const int z = spd[idx_d[k]];
            const int pos = y * dlinesize + x;
            if (z < tmin || z > tmax)
                continue;
            if (!dpd[pos])
                dpd[pos] = (x + y) > max ? max : (x + y);
            dpx[pos] = x;
            dpy[pos] = y;
        }
    }
    // Handle remaining elements
    for (; j < w; j++) {
        const int x = spx[iw1 + j] > max ? max : spx[iw1 + j];
        const int y = spy[iw2 + j] > max ? max : spy[iw2 + j];
        const int z = spd[iwd + j];
        const int pos = y * dlinesize + x;
        if (z < tmin || z > tmax)
            continue;
        if (!dpd[pos])
            dpd[pos] = (x + y) > max ? max : (x + y);
        dpx[pos] = x;
        dpy[pos] = y;
    }
}
}
