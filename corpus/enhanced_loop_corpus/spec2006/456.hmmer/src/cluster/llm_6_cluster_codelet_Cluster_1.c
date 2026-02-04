#include <stdio.h>

#include <inttypes.h>

extern int N;
extern int i;
extern float *diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < N; i++) {
        diff[i-1] = 0.;
    }
}
