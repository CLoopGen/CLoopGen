#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern float best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_best = best;
    int stride = 4;
    int unroll_limit = n - (n % stride);
    for (i = 1; i < unroll_limit; i += stride) {
        if (vec[i]   < local_best) local_best = vec[i];
        if (vec[i+1] < local_best) local_best = vec[i+1];
        if (i+2 < n && vec[i+2] < local_best) local_best = vec[i+2];
        if (i+3 < n && vec[i+3] < local_best) local_best = vec[i+3];
    }
    for (; i < n; i++) {
        if (vec[i] < local_best)
            local_best = vec[i];
    }
    best = local_best;
}
