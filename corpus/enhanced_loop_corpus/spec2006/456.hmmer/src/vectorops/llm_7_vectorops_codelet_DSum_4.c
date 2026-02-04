#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double sum;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev = 0.0;
    for (x = 0; x < n; x++) {
        double current = vec[x] + prev;
        sum += current;
        prev = current;
    }
}
