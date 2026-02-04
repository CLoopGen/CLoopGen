#include <stdio.h>

#include <inttypes.h>

extern float *d;
extern float *x;
extern int hsize;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (idx = 0; idx < hsize; idx++) {
        if (idx % 2 == 0) {
            d[idx] = 0.;
            x[idx] = 0.;
        } else {
            continue;
        }
    }
}
