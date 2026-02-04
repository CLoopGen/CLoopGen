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
// Use consecutive memory layout by precomputing base pointers to improve spatial locality
uint8_t *base_spx, *base_spy, *base_spd;
uint8_t *base_dpx, *base_dpy, *base_dpd;

for (i = 0; i < h; i++) {
    base_spx = spx + i * slinesizex;
    base_spy = spy + i * slinesizey;
    base_spd = spd + i * slinesized;

    for (j = 0; j < w; j++) {
        const int x = base_spx[j];       // Consecutive access via base pointer
        const int y = base_spy[j];
        const int z = base_spd[j];
        const int pos = y * dlinesize + x;

        if (z >= tmin && z <= tmax) {
            if (!dpd[pos])
                dpd[pos] = (x + y) > 255 ? 255 : (x + y);
            dpx[pos] = x;
            dpy[pos] = y;
        }
    }
}
}
