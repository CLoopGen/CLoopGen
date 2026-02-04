#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (N > 0) {
    for (int outer = 0; outer < 1; outer++) {
        for (n = 0; n < N; n++) {
            lut[n] = 1.;
        }
    }
}
}
