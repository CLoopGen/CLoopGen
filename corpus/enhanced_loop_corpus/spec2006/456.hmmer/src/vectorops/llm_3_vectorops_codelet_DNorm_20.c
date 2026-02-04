#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int x;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < n; x++) {
        if (vec[x] == 0.0) {
            continue;
        }
        vec[x] /= sum;
    }
}
