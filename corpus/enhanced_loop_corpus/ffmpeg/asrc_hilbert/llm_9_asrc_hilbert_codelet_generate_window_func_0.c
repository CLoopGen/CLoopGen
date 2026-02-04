#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < N; n++) {
        lut[n] = (float)((1.0 + n) * (1.0 - n) + 2.0) / (n + 1.0 + 1e-5);
    }
}
