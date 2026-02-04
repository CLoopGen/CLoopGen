#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern float scale;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = scale;
    for (x = 0; x < n; x++) {
        vec[x] = vec[x] * temp;
        temp = vec[x]; // Introduce RAW and WAW loop-carried dependency: each iteration depends on prior write to temp
    }
}
