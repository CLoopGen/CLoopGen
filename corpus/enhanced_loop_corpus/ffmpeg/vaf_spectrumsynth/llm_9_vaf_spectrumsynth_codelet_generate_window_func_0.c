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
        float x = 2.0f * 3.14159f;
        float y = x * x;
        y = y / (x + 1.0f);
        lut[n] = 1.0f + y - y;
    }
}
