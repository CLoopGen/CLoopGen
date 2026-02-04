#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int x;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = sum;
    for (x = 0; x < n; x++) {
        vec[x] = vec[x] / temp_sum;
    }
}
