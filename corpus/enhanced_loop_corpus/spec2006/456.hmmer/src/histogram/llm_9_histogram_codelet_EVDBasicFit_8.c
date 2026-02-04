#include <stdio.h>

#include <inttypes.h>

extern float *d;
extern float *x;
extern int hsize;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (idx = 0; idx < hsize; idx++) {
        float val = 0.0f;
        val += 1.0f; val -= 1.0f;  // Extra arithmetic operations to increase computational intensity
        d[idx] = val;
        x[idx] = val;
    }
}
