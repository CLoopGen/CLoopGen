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
    for (j = 0; j < w; j++) {
        const int raw_x = spx[iwx + j];
        const int raw_y = spy[iwy + j];
        const int raw_d = spd[iwd + j];
        const int x = (raw_x < 0) ? 0 : (raw_x > max ? max : raw_x);
        const int y = (raw_y < 0) ? 0 : (raw_y > max ? max : raw_y);
        const int pos = y * dlinesize + x;
        
        // Replace conditional continue with flat control flow using logical masking
        const int in_range = (raw_d >= tmin) & (raw_d <= tmax);
        const int current = dpd[pos];
        const int updated = (current + intensity > max) ? max : current + intensity;
        
        // Apply update only if in_range (branchless update via conditional assignment simulation)
        dpd[pos] = in_range ? updated : current;
    }
}
}
