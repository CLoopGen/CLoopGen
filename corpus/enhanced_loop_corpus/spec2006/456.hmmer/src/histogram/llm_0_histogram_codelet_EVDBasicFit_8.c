#include <stdio.h>

#include <inttypes.h>

extern float *d;
extern float *x;
extern int hsize;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < hsize; i++) {
        for (idx = i; idx <= i; idx++) {
            d[idx] = x[idx] = 0.;
        }
    }
}
