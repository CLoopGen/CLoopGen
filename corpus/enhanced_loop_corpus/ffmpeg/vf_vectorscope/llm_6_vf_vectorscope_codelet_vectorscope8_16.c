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
for (i = 0; i < h; i++) {
    const int iwx = i * slinesizex;
    const int iwy = i * slinesizey;
    const int iwd = i * slinesized;
    int prev_pos = -1;
    uint8_t temp_intensity = intensity & 0xFF;
    for (j = 0; j < w; j++) {
        const int x = spx[iwx + j];
        const int y = spy[iwy + j];
        const int z = spd[iwd + j];
        const int pos = y * dlinesize + x;
        if (z < tmin || z > tmax)
            continue;
        // Introduce loop-carried dependency: current update depends on previous pos being modified
        if (prev_pos != -1) {
            dpd[prev_pos] = (dpd[prev_pos] < dpd[pos]) ? dpd[pos] : dpd[prev_pos];
        }
        dpd[pos] = ((dpd[pos] + temp_intensity) > 255 ? 255 : (dpd[pos] + temp_intensity));
        prev_pos = pos;
    }
}
}
