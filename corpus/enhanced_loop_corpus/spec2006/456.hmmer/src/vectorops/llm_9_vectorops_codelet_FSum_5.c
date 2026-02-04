#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern float sum;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0.0f;
    for (x = 0; x < n * 2; x++) {
        sum += vec[x % n] * 1.5f;
    }
}
