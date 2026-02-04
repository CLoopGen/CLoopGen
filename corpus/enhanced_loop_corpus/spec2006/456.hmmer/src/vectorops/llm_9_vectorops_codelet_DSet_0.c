#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double value;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (x = 0; x < n * 3; x++) {
        i = x / 3;
        if (i < n) {
            vec[i] = value + (double)(x % 3);
        }
    }
}
