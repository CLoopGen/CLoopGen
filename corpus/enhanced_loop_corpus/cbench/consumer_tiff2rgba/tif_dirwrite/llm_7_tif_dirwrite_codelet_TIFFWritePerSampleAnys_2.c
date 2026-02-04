#include <stdio.h>

#include <inttypes.h>

extern double v;
extern double *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < samples; i++) {
        w[i] = w[i-1]; // Introduce loop-carried dependence: each iteration depends on previous (RAW)
    }
    if (samples > 0) {
        w[0] = v; // Initialize first element to maintain consistency with original intent
    }
}
