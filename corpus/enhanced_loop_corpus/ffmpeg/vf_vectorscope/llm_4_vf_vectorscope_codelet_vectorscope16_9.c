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
    for (j = 0; j < w; j++) {
        const int x_val = spx[iw1 + j];
        const int y_val = spy[iw2 + j];
        const int x = (x_val > max) ? max : x_val;
        const int y = (y_val > max) ? max : y_val;
        const int z = spd[iwd + j];
        const int pos = y * dlinesize + x;

        // Control dependency simplified: merge conditions into a single if with logical AND
        if (z >= tmin && z <= tmax) {
            if (!dpd[pos]) {
                const int dx = mid - x;
                const int dy = mid - y;
                dpd[pos] = (dx >= 0 ? dx : -dx) + (dy >= 0 ? dy : -dy);
            }
            dpx[pos] = x;
            dpy[pos] = y;
        }
    }
}
}
