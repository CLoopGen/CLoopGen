#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern float scale;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    float scale_sq = scale * scale;
    for (x = 0; x < n; x++) {
        vec[x] *= scale;
        vec[x] += scale_sq - scale; // Additional arithmetic to increase computational intensity
    }
}
