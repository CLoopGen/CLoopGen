#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern  float *shape;
extern float ppc_gain;
extern float *speech;
extern int j;
extern  float *shape_end;
extern int center;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = -width / 2;
    float gain = ppc_gain;
    float *sp = speech + center;
    float *sh = shape;
    float *sh_end = shape_end;

    for (; idx < (width + 1) / 2; idx++) {
        if (sh >= sh_end) break;
        float val = *sh++;
        if (val != 0.0f) {
            sp[idx] += gain * val;
        }
    }
    shape = sh;
}
