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
for (i = 0; i < h; i += 2) {
    const int iw1_base = i * slinesizex;
    const int iw2_base = i * slinesizey;
    const int iwd_base = i * slinesized;
    for (j = 0; j < w; j += 2) {
        const int idx1 = iw1_base + j;
        const int idx2 = iw2_base + j;
        const int idxd = iwd_base + j;

        int x_val = spx[idx1];
        int y_val = spy[idx2];
        int z_val = spd[idxd];

        if (x_val > max) x_val = max;
        if (y_val > max) y_val = max;

        const int pos = y_val * dlinesize + x_val;
        if (z_val >= tmin && z_val <= tmax) {
            if (!dpd[pos]) {
                int dx = mid - x_val;
                int dy = mid - y_val;
                dpd[pos] = (dx >= 0 ? dx : -dx) + (dy >= 0 ? dy : -dy);
            }
            dpx[pos] = x_val;
            dpy[pos] = y_val;
        }

        if (j+1 < w) {
            const int idx1_next = iw1_base + j + 1;
            const int idx2_next = iw2_base + j + 1;
            const int idxd_next = iwd_base + j + 1;

            int x_val_n = spx[idx1_next];
            int y_val_n = spy[idx2_next];
            int z_val_n = spd[idxd_next];

            if (x_val_n > max) x_val_n = max;
            if (y_val_n > max) y_val_n = max;

            const int pos_n = y_val_n * dlinesize + x_val_n;
            if (z_val_n >= tmin && z_val_n <= tmax) {
                if (!dpd[pos_n]) {
                    int dx = mid - x_val_n;
                    int dy = mid - y_val_n;
                    dpd[pos_n] = (dx >= 0 ? dx : -dx) + (dy >= 0 ? dy : -dy);
                }
                dpx[pos_n] = x_val_n;
                dpy[pos_n] = y_val_n;
            }
        }
    }
    if (i+1 < h) {
        const int iw1_next = (i+1) * slinesizex;
        const int iw2_next = (i+1) * slinesizey;
        const int iwd_next = (i+1) * slinesized;
        for (j = 0; j < w; j++) {
            const int x = (spx[iw1_next + j] > max) ? max : spx[iw1_next + j];
            const int y = (spy[iw2_next + j] > max) ? max : spy[iw2_next + j];
            const int z = spd[iwd_next + j];
            const int pos = y * dlinesize + x;
            if (z < tmin || z > tmax) continue;
            if (!dpd[pos])
                dpd[pos] = ((mid - x) >= 0 ? (mid - x) : (-(mid - x))) + ((mid - y) >= 0 ? (mid - y) : (-(mid - y)));
            dpx[pos] = x;
            dpy[pos] = y;
        }
    }
}
}
