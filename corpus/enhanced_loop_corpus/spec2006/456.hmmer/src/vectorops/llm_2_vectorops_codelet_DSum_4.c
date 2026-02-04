#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double sum;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (x = 0; x < n; x += stride) {
        if (x < n) sum += vec[x];
    }
}
