#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (iterate from end to start)
    for (n = N - 1; n >= 0; n--) {
        float center = (N - 1) / 2.0f;
        float norm = (n - center) / center;
        lut[n] = 1.0f - norm * norm;
    }
}
