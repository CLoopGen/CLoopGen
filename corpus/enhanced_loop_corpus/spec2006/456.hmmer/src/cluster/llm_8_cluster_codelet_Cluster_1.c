#include <stdio.h>

#include <inttypes.h>

extern int N;
extern int i;
extern float *diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N - 1; i += 2) {
        diff[i] = 0.;
        if (i + 1 < N - 1) {
            diff[i + 1] = 0.;
        }
    }
}
