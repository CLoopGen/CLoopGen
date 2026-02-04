#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_sum = sum;
    for (x = 0; x < n; x++) {
        vec[x] = vec[x] / temp_sum;
    }
}
