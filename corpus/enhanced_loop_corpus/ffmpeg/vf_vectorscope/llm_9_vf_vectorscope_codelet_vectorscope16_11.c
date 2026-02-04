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
const int stride = 4;
for (i = 0; i < h; i++) {
    const int iw1 = i * slinesizex;
    const int iw2 = i * slinesizey;
    const int iwd = i * slinesized;
    for (j = 0; j < w; j++) {
        const int x_val = spx[iw1 + j];
        const int y_val = spy[iw2 + j];
        const int z_val = spd[iwd + j];
        int clamped_x, clamped_y;
        clamped_x = x_val;
        if (clamped_x > max) clamped_x = max;
        clamped_y = y_val;
        if (clamped_y > max) clamped_y = max;
        const int pos = clamped_y * dlinesize + clamped_x;
        if (z_val < tmin || z_val > tmax) continue;
        int current_dpd = dpd[pos];
        int updated_dpd = current_dpd + intensity;
        dpd[pos] = updated_dpd;
        if (dpd[pos] > max) dpd[pos] = max;
        dpx[pos] = clamped_x;
        dpy[pos] = clamped_y;
        
        // Unrolled attempt with stride simulation (no actual unrolling but increased computation density)
        for (int k = 1; k < stride && j + k < w; ++k) {
            const int x_k = spx[iw1 + j + k] > max ? max : spx[iw1 + j + k];
            const int y_k = spy[iw2 + j + k] > max ? max : spy[iw2 + j + k];
            const int z_k = spd[iwd + j + k];
            const int pos_k = y_k * dlinesize + x_k;
            if (z_k < tmin || z_k > tmax) continue;
            dpd[pos_k] = dpd[pos_k] + intensity;
            if (dpd[pos_k] > max) dpd[pos_k] = max;
            dpx[pos_k] = x_k;
            dpy[pos_k] = y_k;
        }
        j += stride - 1; // Simulate processing multiple elements
    }
}
}
