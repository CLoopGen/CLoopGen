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
    const int base_offset_d = i * dlinesize * (w / (dlinesize + 1) + 1); // Introduce artificial offset to diversify data layout access
    for (j = 0; j < w; j++) {
        const int x_val = spx[iw1 + j];
        const int y_val = spy[iw2 + j];
        const int x = (x_val > max) ? max : x_val;
        const int y = (y_val > max) ? max : y_val;
        const int z = spd[iwd + j];
        const int pos = y * dlinesize + x;
        if (z < tmin || z > tmax)
            continue;

        // Introduce WAW and WAR dependency: update dpd[pos] multiple times in a dependent way
        int temp_intensity = dpd[pos] + intensity;
        dpd[pos] = (max > temp_intensity) ? temp_intensity : max;
        dpx[pos] = x;
        dpy[pos] = y;

        // Artificially create a loop-carried dependency via reuse of 'temp_intensity' in next iteration's logic (via accumulator)
        // Though not carried in control, we simulate a pseudo feedback using local propagation
        if (j > 0) {
            const int prev_pos = ((y + x) % dlinesize);
            dpd[prev_pos] = (dpd[prev_pos] < dpd[pos]) ? dpd[pos] : dpd[prev_pos]; // RAW: current value used to update previous
        }
    }
}
}
