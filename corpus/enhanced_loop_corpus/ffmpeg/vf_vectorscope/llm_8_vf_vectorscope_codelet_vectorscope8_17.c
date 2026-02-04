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
for (i = 0; i < h; i += 2) {
    const int iw1_base = i * slinesizex;
    const int iw2_base = i * slinesizey;
    const int iwd_base = i * slinesized;
    for (j = 0; j < w; j += 2) {
        const int indices[4][2] = {{0,0}, {0,1}, {1,0}, {1,1}};
        for (int k = 0; k < 4; ++k) {
            int ii = i + indices[k][0];
            int jj = j + indices[k][1];
            if (ii >= h || jj >= w) continue;
            const int idx_x = iw1_base + slinesizex * (ii - i) + jj;
            const int idx_y = iw2_base + slinesizey * (ii - i) + jj;
            const int idx_z = iwd_base + slinesized * (ii - i) + jj;
            const int x = spx[idx_x];
            const int y = spy[idx_y];
            const int z = spd[idx_z];
            const int pos = y * dlinesize + x;
            if (z < tmin || z > tmax)
                continue;
            const int dx = 128 - x;
            const int dy = 128 - y;
            const int abs_dx = dx ^ ((dx >> 31) & dx);
            const int abs_dy = dy ^ ((dy >> 31) & dy);
            if (!dpd[pos])
                dpd[pos] = abs_dx + abs_dy;
            dpx[pos] = x;
            dpy[pos] = y;
        }
    }
}
}
