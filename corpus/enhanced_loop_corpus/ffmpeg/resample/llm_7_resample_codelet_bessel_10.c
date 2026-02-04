#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double v;
extern double lastv;
extern double t;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double next_t, prev_t = t;
    double accum_v = v;
    double prev_lastv = lastv;
    for (i = 1; accum_v != prev_lastv; i++) {
        prev_lastv = accum_v;
        next_t = prev_t * x / (i * i);
        accum_v += next_t;
        prev_t = next_t;
    }
    v = accum_v;
    t = prev_t;
    lastv = prev_lastv;
}
