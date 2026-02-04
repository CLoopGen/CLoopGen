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
for (i = 0; i < h; i++) {
    const int iw1 = i * slinesizex;
    const int iw2 = i * slinesizey;
    const int iwd = i * slinesized;
    for (j = 0; j < w; j++) {
        const int x = spx[iw1 + j];
        const int y = spy[iw2 + j];
        const int z = spd[iwd + j];
        const int clamped_x = (x > max) ? max : x;
        const int clamped_y = (y > max) ? max : y;
        const int pos = clamped_y * dlinesize + clamped_x;
        
        if (!(z < tmin || z > tmax)) {
            dpd[pos] = (dpd[pos] + intensity > max) ? max : dpd[pos] + intensity;
            dpx[pos] = clamped_x;
            dpy[pos] = clamped_y;
        }
    }
}
}
