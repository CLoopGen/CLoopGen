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
    int prev_x = mid, prev_y = mid;
    for (j = 0; j < w; j++) {
        int x = spx[iw1 + j];
        int y = spy[iw2 + j];
        if (x > max) x = max;
        if (y > max) y = max;
        const int z = spd[iwd + j];
        const int pos = y * dlinesize + x;
        if (z < tmin || z > tmax)
            continue;
        const int smooth_x = (x + prev_x) / 2;
        const int smooth_y = (y + prev_y) / 2;
        const int smoothed_pos = smooth_y * dlinesize + smooth_x;
        const int dist_x = smooth_x - mid;
        const int dist_y = smooth_y - mid;
        const int abs_dist = (dist_x >= 0 ? dist_x : -dist_x) + (dist_y >= 0 ? dist_y : -dist_y);
        if (!dpd[smoothed_pos]) {
            dpd[smoothed_pos] = abs_dist;
        }
        dpx[smoothed_pos] = smooth_x;
        dpy[smoothed_pos] = smooth_y;
        prev_x = x;
        prev_y = y;
    }
}
}
