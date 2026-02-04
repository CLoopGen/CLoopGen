#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int i;
extern double best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_best = best;
    for (i = 1; i < n; i += 2) {
        if (i + 1 < n) {
            double val1 = vec[i];
            double val2 = vec[i + 1];
            if (val1 > val2) {
                if (val1 > local_best)
                    local_best = val1;
            } else {
                if (val2 > local_best)
                    local_best = val2;
            }
        } else {
            if (vec[i] > local_best)
                local_best = vec[i];
        }
    }
    best = local_best;
}
