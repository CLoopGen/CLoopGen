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
for (j = 0; j < w; j++) {
    for (i = 0; i < h; i++) {
        const int idx_x = i * slinesizex + j;
        const int idx_y = i * slinesizey + j;
        const int idx_d = i * slinesized + j;
        const int x = spx[idx_x];
        const int y = spy[idx_y];
        const int z = spd[idx_d];
        const int pos = y * dlinesize + x;
        if (z < tmin || z > tmax)
            continue;
        dpd[pos] = ((dpd[pos] + intensity) > 255 ? 255 : dpd[pos] + intensity);
    }
}
}
