#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (x = 0; x < n; x++) {
        vec[x] = 1.0 / (double)n;
        vec[x] *= vec[x];  // Additional arithmetic: square the result
    }
}
