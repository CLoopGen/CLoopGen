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
for (i = 0; i < h; i++) {
    const int iw1 = i * slinesizex;
    const int iw2 = i * slinesizey;
    const int iwd = i * slinesized;
    for (j = 0; j < w; j += 4) {
        const int pos1 = spy[iw2 + j] * dlinesize + spx[iw1 + j];
        const int pos2 = spy[iw2 + j + 1] * dlinesize + spx[iw1 + j + 1];
        const int pos3 = spy[iw2 + j + 2] * dlinesize + spx[iw1 + j + 2];
        const int pos4 = spy[iw2 + j + 3] * dlinesize + spx[iw1 + j + 3];
        
        if (spd[iwd + j] >= tmin && spd[iwd + j] <= tmax) {
            dpd[pos1] = (255 > (dpd[pos1] + intensity)) ? (dpd[pos1] + intensity) : 255;
            dpx[pos1] = spx[iw1 + j];
            dpy[pos1] = spy[iw2 + j];
        }
        if (j + 1 < w && spd[iwd + j + 1] >= tmin && spd[iwd + j + 1] <= tmax) {
            dpd[pos2] = (255 > (dpd[pos2] + intensity)) ? (dpd[pos2] + intensity) : 255;
            dpx[pos2] = spx[iw1 + j + 1];
            dpy[pos2] = spy[iw2 + j + 1];
        }
        if (j + 2 < w && spd[iwd + j + 2] >= tmin && spd[iwd + j + 2] <= tmax) {
            dpd[pos3] = (255 > (dpd[pos3] + intensity)) ? (dpd[pos3] + intensity) : 255;
            dpx[pos3] = spx[iw1 + j + 2];
            dpy[pos3] = spy[iw2 + j + 2];
        }
        if (j + 3 < w && spd[iwd + j + 3] >= tmin && spd[iwd + j + 3] <= tmax) {
            dpd[pos4] = (255 > (dpd[pos4] + intensity)) ? (dpd[pos4] + intensity) : 255;
            dpx[pos4] = spx[iw1 + j + 3];
            dpy[pos4] = spy[iw2 + j + 3];
        }
    }
}
}
