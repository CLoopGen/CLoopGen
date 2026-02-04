#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_best = best;
    for (i = 1; i < n; i += 2) {
        int j = i + 1;
        float val_i = vec[i];
        float val_j = (j < n) ? vec[j] : -__builtin_inff();
        if (val_i > vec[local_best]) {
            local_best = i;
        }
        if (val_j > vec[local_best]) {
            local_best = j;
        }
    }
    best = local_best;
}
