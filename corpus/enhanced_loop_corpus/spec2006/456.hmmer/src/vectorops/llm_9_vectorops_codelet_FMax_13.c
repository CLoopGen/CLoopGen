#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern float best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    float local_best = best;
    for (i = 1; i < n; i++) {
        local_best = (vec[i] > local_best) ? vec[i] : local_best;
    }
    best = local_best;
}
