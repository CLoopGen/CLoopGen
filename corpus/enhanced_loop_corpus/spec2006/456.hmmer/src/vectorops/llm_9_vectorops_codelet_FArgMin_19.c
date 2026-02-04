#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    int limit = n - (n % stride);
    for (i = 1; i < limit; i += stride) {
        float temp_best = vec[best];
        if (vec[i]   < temp_best) { best = i;   temp_best = vec[i]; }
        if (vec[i+1] < temp_best) { best = i+1; temp_best = vec[i+1]; }
        if (vec[i+2] < temp_best) { best = i+2; temp_best = vec[i+2]; }
        if (vec[i+3] < temp_best) { best = i+3; }
    }
    for (; i < n; i++) {
        if (vec[i] < vec[best])
            best = i;
    }
}
