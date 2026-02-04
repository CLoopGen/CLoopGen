#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float a = 2.0f, b = 0.5f, c = -1.0f;
    for (n = 0; n < N; n++) {
        float x = (float)n * 0.001f;
        float y = a * x * x + b * x + c;
        lut[n] = y * y + 1.0f;
    }
}
