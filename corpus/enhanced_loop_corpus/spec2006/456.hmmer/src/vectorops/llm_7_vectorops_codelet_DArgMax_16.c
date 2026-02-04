#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_best = best;
    for (i = 1; i < n; i += 2) {
        int j = i + 1;
        if (j < n) {
            double val_i = vec[i];
            double val_j = vec[j];
            if (val_i > val_j && val_i > vec[local_best]) {
                local_best = i;
            } else if (val_j >= val_i && val_j > vec[local_best]) {
                local_best = j;
            }
        } else {
            if (vec[i] > vec[local_best]) {
                local_best = i;
            }
        }
    }
    best = local_best;
}
