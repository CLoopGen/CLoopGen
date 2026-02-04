#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern float best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_best = best;
    for (i = 1; i < n; i += 2) {
        float val1 = vec[i];
        float val2 = (i + 1 < n) ? vec[i + 1] : val1;
        float max_val = (val1 > val2) ? val1 : val2;
        if (max_val > local_best)
            local_best = max_val;
    }
    best = local_best;
}
