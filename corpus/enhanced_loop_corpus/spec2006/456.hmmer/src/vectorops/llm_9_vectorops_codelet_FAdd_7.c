#include <stdio.h>

#include <inttypes.h>

extern float *vec1;
extern float *vec2;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < n * 2; x++) {
        int idx = x / 2;
        if (idx < n) {
            vec1[idx] += vec2[idx] * 1.5f;
        }
    }
}
