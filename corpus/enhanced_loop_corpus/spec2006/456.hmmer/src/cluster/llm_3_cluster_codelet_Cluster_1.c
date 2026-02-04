#include <stdio.h>

#include <inttypes.h>

extern int N;
extern int i;
extern float *diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = N - 2; i >= 0; i--)
    diff[i] = 0.;
}
