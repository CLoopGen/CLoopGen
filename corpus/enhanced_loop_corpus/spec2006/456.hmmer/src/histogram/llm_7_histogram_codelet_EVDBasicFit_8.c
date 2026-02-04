#include <stdio.h>

#include <inttypes.h>

extern float *d;
extern float *x;
extern int hsize;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate loop-carried dependencies by unrolling and independent updates
    int i;
    for (i = 0; i < hsize; i += 2) {
        if (i < hsize) {
            d[i] = 0.;
            x[i] = 0.;
        }
        if (i + 1 < hsize) {
            d[i+1] = 0.;
            x[i+1] = 0.;
        }
        // No inter-iteration dependencies; each iteration is independent
    }
    // Handle possible odd-sized hsize safely without introducing dependencies
}
