#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 1.0 / (double)n;
    for (x = 0; x < n; x++) {
        vec[x] = temp;
    }
}
