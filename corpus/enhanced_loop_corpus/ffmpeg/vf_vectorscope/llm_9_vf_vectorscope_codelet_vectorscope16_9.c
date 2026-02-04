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
for (i = 1; i < h - 1; i++) {
    const int iw1 = i * slinesizex;
    const int iw2 = i * slinesizey;
    const int iwd = i * slinesized;
    for (j = 1; j < w - 1; j++) {
        const int center_x = (spx[iw1 + j] > max) ? max : spx[iw1 + j];
        const int center_y = (spy[iw2 + j] > max) ? max : spy[iw2 + j];
        const int center_z = spd[iwd + j];

        if (center_z < tmin || center_z > tmax) continue;

        const int pos = center_y * dlinesize + center_x;

        if (!dpd[pos]) {
            int diff_x = mid - center_x;
            int diff_y = mid - center_y;
            int abs_dx = diff_x ^ (diff_x >> (sizeof(int)*8-1));
            abs_dx -= (diff_x >> (sizeof(int)*8-1));
            int abs_dy = diff_y ^ (diff_y >> (sizeof(int)*8-1));
            abs_dy -= (diff_y >> (sizeof(int)*8-1));
            dpd[pos] = abs_dx + abs_dy;
        }
        dpx[pos] = center_x;
        dpy[pos] = center_y;

        const int neighbors[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for (int n = 0; n < 4; n++) {
            int ni = i + neighbors[n][0];
            int nj = j + neighbors[n][1];
            if (ni <= 0 || ni >= h - 1 || nj <= 0 || nj >= w - 1) continue;

            const int niw1 = ni * slinesizex;
            const int niw2 = ni * slinesizey;
            const int niwd = ni * slinesized;

            const int nx = (spx[niw1 + nj] > max) ? max : spx[niw1 + nj];
            const int ny = (spy[niw2 + nj] > max) ? max : spy[niw2 + nj];
            const int nz = spd[niwd + nj];

            if (nz < tmin || nz > tmax) continue;

            const int npos = ny * dlinesize + nx;
            if (!dpd[npos]) {
                int ndx = mid - nx;
                int ndy = mid - ny;
                dpd[npos] = (ndx >= 0 ? ndx : -ndx) + (ndy >= 0 ? ndy : -ndy);
            }
            dpx[npos] = nx;
            dpy[npos] = ny;
        }
    }
}
}
