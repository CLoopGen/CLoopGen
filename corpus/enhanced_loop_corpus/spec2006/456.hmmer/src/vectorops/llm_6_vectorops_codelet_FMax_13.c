#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern float best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_best = best;
    for (i = 1; i < n; i++) {
        if (vec[i] > temp_best)
            temp_best = vec[i];
    }
    best = temp_best;
}
