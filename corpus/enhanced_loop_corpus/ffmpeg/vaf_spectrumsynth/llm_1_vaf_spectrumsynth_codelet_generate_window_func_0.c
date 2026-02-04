#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer_n;
for (outer_n = 0; outer_n < N; outer_n++) {
    n = outer_n;
    {
        lut[n] = 1.;
    }
}
}
