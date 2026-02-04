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
for (i = 0; i < h; i++) {
    const int iw1 = i * slinesizex;
    const int iw2 = i * slinesizey;
    const int iwd = i * slinesized;
    int count = 0;
    for (j = 0; j < w && count < 8; j++) {
        const int raw_x = spx[iw1 + j];
        const int raw_y = spy[iw2 + j];
        const int raw_z = spd[iwd + j];
        int x = raw_x;
        int y = raw_y;
        if (raw_x > max) x = max;
        if (raw_y > max) y = max;
        const int z = raw_z;
        const int pos = y * dlinesize + x;
        if (z >= tmin && z <= tmax) {
            if (!dpd[pos]) {
                int sum = x + y;
                dpd[pos] = (sum > max) ? max : sum;
            }
            dpx[pos] = x;
            dpy[pos] = y;
            count++;
        }
    }
}
}
