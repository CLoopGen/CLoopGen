#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < N; n += 2)
        lut[n] = 1.;
    for (n = 1; n < N; n += 2)
        lut[n] = 1.;
}
