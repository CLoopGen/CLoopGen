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
for (i = 0; i < h; i += 2) {
    for (j = 0; j < w; j++) {
        const int offsets_x[4] = {i * slinesizex + j, (i + 1) * slinesizex + j};
        const int offsets_y[4] = {i * slinesizey + j, (i + 1) * slinesizey + j};
        const int offsets_d[4] = {i * slinesized + j, (i + 1) * slinesized + j};
        for (int k = 0; k < (i + 1 < h ? 2 : 1); ++k) {
            const int x = spx[offsets_x[k]] > max ? max : spx[offsets_x[k]];
            const int y = spy[offsets_y[k]] > max ? max : spy[offsets_y[k]];
            const int z = spd[offsets_d[k]];
            const int pos = y * dlinesize + x;
            if (z >= tmin && z <= tmax) {
                dpd[pos] = dpd[pos] + intensity > max ? max : dpd[pos] + intensity;
            }
        }
    }
}
}
