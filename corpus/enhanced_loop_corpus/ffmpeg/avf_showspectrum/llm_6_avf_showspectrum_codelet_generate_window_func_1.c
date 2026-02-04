#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = 1.0;
    for (n = 0; n < N; n++) {
        lut[n] = temp;
        temp = lut[n]; // Introduce RAW dependency: current iteration reads value written in same iteration
    }
}
