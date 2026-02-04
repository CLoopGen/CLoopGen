#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < n; x += 2) {
        if (x + 1 < n) {
            vec[x] /= sum;
            vec[x + 1] /= sum;
        } else {
            vec[x] /= sum;
        }
    }
}
