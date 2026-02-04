#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < N; outer += 2) {
    lut[outer] = 1.;
    if (outer + 1 < N) {
        lut[outer + 1] = 1.;
    }
}
}
