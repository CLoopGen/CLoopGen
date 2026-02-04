#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = 0.0f;
    for (x = 0; x < n; x++) {
        temp += 1.0f / (float)n;
        vec[x] = temp;
    }
}
