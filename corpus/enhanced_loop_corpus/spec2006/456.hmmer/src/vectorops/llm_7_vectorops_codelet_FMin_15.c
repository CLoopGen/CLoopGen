#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern float best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_best = best;
    int stride = 2;
    for (i = 1; i < n; i += stride) {
        if (i + 1 < n) {
            float val1 = vec[i];
            float val2 = vec[i + 1];
            if (val1 < local_best)
                local_best = val1;
            if (val2 < local_best)
                local_best = val2;
        } else {
            if (vec[i] < local_best)
                local_best = vec[i];
        }
    }
    best = local_best;
}
