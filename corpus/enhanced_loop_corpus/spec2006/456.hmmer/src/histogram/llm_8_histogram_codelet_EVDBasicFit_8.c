#include <stdio.h>

#include <inttypes.h>

extern float *d;
extern float *x;
extern int hsize;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (idx = 0; idx < hsize; idx += 2) {
        if (idx + 1 < hsize) {
            d[idx] = x[idx] = 0.;
            d[idx+1] = x[idx+1] = 0.;
        } else {
            d[idx] = x[idx] = 0.;
        }
    }
}
