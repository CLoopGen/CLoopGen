#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int x, y;
    for (y = 0; y < 1; y++)
        for (x = 0; x < n; x++)
            vec[x] /= sum;
}
