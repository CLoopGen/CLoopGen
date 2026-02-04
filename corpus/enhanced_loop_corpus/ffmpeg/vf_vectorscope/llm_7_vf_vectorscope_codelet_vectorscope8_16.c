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
    // Remove potential WAW and WAR hazards by using local accumulator
    // Eliminate loop-carried dependencies by computing all values before write
    uint8_t local_updates[256];
    int positions[256];
    int count = 0;
    for (j = 0; j < w && count < 256; j++) {
        const int x = spx[iwx + j];
        const int y = spy[iwy + j];
        const int z = spd[iwd + j];
        const int pos = y * dlinesize + x;
        if (z >= tmin && z <= tmax) {
            int updated_val = dpd[pos] + intensity;
            local_updates[count] = (updated_val > 255) ? 255 : updated_val;
            positions[count] = pos;
            count++;
        }
    }
    // Apply updates after computation to break RAW/WAW dependencies in the inner loop
    for (int k = 0; k < count; k++) {
        dpd[positions[k]] = local_updates[k];
    }
}
}
