#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double scale;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_scale = scale;
    for (x = 0; x < n; x += 2) {
        if (x + 1 < n) {
            // Eliminate loop-carried dependencies by processing two independent elements per iteration
            double val1 = vec[x] * local_scale;
            double val2 = vec[x + 1] * local_scale;
            vec[x] = val1;
            vec[x + 1] = val2;
        } else {
            vec[x] *= local_scale;
        }
    }
}
