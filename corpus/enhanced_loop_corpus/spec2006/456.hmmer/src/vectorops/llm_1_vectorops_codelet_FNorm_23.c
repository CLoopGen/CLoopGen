#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        x = 0;
        for (; x < n; x++)
            vec[x] = 1. / (float)n;
    }
}
