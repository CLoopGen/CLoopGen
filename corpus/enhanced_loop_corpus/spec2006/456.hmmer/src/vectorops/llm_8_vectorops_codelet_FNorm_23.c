#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (x = 0; x < n; x += 2) {
        if (x + 1 < n) {
            vec[x]     = 1.0f / (float)(n + x);
            vec[x + 1] = 1.0f / (float)(n - x);
        } else {
            vec[x] = 1.0f / (float)n;
        }
    }
}
