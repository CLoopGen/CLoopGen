#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float inv_sum = 1.0f / sum;
    for (x = 0; x < n; x++) {
        vec[x] *= inv_sum;
    }
}
