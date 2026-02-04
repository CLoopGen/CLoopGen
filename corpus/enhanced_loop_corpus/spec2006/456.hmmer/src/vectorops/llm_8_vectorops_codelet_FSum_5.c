#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern float sum;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0.0f;
    for (x = 0; x < n; x += 2) {
        if (x + 1 < n) {
            sum += vec[x] + vec[x + 1];
        } else {
            sum += vec[x];
        }
    }
}
