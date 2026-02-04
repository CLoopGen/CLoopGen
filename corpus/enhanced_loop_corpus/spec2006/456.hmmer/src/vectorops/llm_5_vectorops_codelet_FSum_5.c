#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern float sum;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < n; x++) {
        if (vec[x] < 0.0f) {
            continue;
        }
        sum += vec[x];
    }
}
