#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (x = 0; x < n; x += step) {
        if (x + 1 < n) {
            vec[x] = 1.0 / (double)n;
            vec[x + 1] = 1.0 / (double)n;
        } else {
            vec[x] = 1.0 / (double)n;
        }
    }
}
