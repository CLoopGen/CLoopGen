#include <stdio.h>

#include <inttypes.h>

extern double v;
extern double *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (samples > 0) {
        w[0] = v;
        for (i = 1; i < samples; i++) {
            w[i] = w[i-1]; // Introduce WAW and loop-carried dependence
        }
    }
}
