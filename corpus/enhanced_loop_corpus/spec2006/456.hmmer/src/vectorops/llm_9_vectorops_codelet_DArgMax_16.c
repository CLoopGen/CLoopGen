#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    double temp_best_val = vec[best];
    for (i = 1; i < n; i++) {
        double diff = vec[i] - temp_best_val;
        if (diff > 0.0) {
            temp_best_val = vec[i];
            best = i;
        }
    }
}
