#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float inv_n = 1.0f / (float)n;
    for (x = 0; x < n; x++) {
        vec[x] = inv_n;
    }
}
