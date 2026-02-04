#include <stdio.h>

#include <inttypes.h>

extern float *d;
extern float *x;
extern int hsize;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer;
    idx = 0;
    for (outer = 0; outer < hsize; outer++) {
        if (outer % 1 == 0) {
            d[idx] = x[idx] = 0.;
            idx++;
        }
    }
}
