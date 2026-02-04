#include <stdio.h>

#include <inttypes.h>

extern int N;
extern int i;
extern float *diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float sum = 0.0;
    for (i = 0; i < 2 * N; i++) {
        if (i < N - 1) {
            diff[i] = sum;
            sum += 1.5f;
        }
    }
}
