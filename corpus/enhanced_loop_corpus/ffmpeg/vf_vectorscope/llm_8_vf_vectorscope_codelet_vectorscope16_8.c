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
extern uint16_t *dpd;
extern  int max;
extern  int tmin;
extern  int tmax;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    const int iwx = i * slinesizex;
    const int iwy = i * slinesizey;
    const int iwd = i * slinesized;
    for (j = 0; j < w; j += 2) {
        const int x1 = spx[iwx + j] > max ? max : spx[iwx + j];
        const int y1 = spy[iwy + j] > max ? max : spy[iwy + j];
        const int z1 = spd[iwd + j];
        const int pos1 = y1 * dlinesize + x1;
        if (!(z1 < tmin || z1 > tmax)) {
            dpd[pos1] = dpd[pos1] + intensity > max ? max : dpd[pos1] + intensity;
        }
        if (j + 1 < w) {
            const int x2 = spx[iwx + j + 1] > max ? max : spx[iwx + j + 1];
            const int y2 = spy[iwy + j + 1] > max ? max : spy[iwy + j + 1];
            const int z2 = spd[iwd + j + 1];
            const int pos2 = y2 * dlinesize + x2;
            if (!(z2 < tmin || z2 > tmax)) {
                dpd[pos2] = dpd[pos2] + intensity > max ? max : dpd[pos2] + intensity;
            }
        }
    }
}
}
