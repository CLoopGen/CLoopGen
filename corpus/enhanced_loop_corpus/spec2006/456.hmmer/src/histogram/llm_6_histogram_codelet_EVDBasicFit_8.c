#include <stdio.h>

#include <inttypes.h>

extern float *d;
extern float *x;
extern int hsize;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp;
    for (idx = 0; idx < hsize; idx++) {
        temp = x[idx] + d[idx];  // Introduce RAW dependency: use before assignment
        d[idx] = 0.;
        x[idx] = temp;            // WAW dependency with previous x[idx], and WAR if parallelized
    }
}
