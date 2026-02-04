#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double sum;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0.0;
    for (x = 0; x < n * 2; x++) {
        sum += vec[x % n] * 1.5;
    }
}
