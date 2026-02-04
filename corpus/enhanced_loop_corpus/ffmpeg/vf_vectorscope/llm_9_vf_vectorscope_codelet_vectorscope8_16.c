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
extern uint8_t *dpd;
extern  int tmin;
extern  int tmax;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    for (j = 0; j < w; j++) {
        const int iwx1 = i * slinesizex;
        const int iwy1 = i * slinesizey;
        const int iwd1 = i * slinesized;
        const int x1 = spx[iwx1 + j];
        const int y1 = spy[iwy1 + j];
        const int z1 = spd[iwd1 + j];
        const int pos1 = y1 * dlinesize + x1;
        if (z1 >= tmin && z1 <= tmax) {
            dpd[pos1] = (dpd[pos1] + intensity > 255) ? 255 : dpd[pos1] + intensity;
        }

        if (i + 1 < h) {
            const int iwx2 = (i + 1) * slinesizex;
            const int iwy2 = (i + 1) * slinesizey;
            const int iwd2 = (i + 1) * slinesized;
            const int x2 = spx[iwx2 + j];
            const int y2 = spy[iwy2 + j];
            const int z2 = spd[iwd2 + j];
            const int pos2 = y2 * dlinesize + x2;
            if (z2 >= tmin && z2 <= tmax) {
                dpd[pos2] = (dpd[pos2] + intensity > 255) ? 255 : dpd[pos2] + intensity;
            }
        }
    }
}
}
