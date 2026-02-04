#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y;
    for (x = 0; x < n * 2; x++) {
        y = x % n;
        vec[y] = (1.0f + (float)y) / (float)(n + 1);
    }
}
