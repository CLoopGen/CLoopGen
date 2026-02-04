#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double scale;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = scale;
    for (x = 0; x < n; x++) {
        vec[x] *= temp;
        temp = vec[x]; // Introduce RAW and WAW loop-carried dependency: each iteration depends on prior write to temp
    }
}
