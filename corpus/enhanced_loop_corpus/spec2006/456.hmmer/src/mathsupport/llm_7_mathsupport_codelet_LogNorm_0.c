#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;
extern float max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_max = -__FLT_MAX__;
    int i;
    for (i = 0; i < n; i += 2) {
        float candidate1 = (i < n) ? vec[i] : -__FLT_MAX__;
        float candidate2 = (i + 1 < n) ? vec[i + 1] : -__FLT_MAX__;
        if (candidate1 > local_max)
            local_max = candidate1;
        if (candidate2 > local_max)
            local_max = candidate2;
    }
    if (local_max > max)
        max = local_max;
}
