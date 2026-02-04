#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *hist;
extern  double *median;
extern int i;
extern double err;
extern double sum_sq_err;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_sum = 0.0;
    int limit = 3 * 256 * 4; // Increased trip count
    for (i = 0; i < limit; i++) {
        int idx = i % (3 * 256);
        double diff = median[idx] - (double)hist[idx];
        local_sum += diff * diff * 0.5; // Additional arithmetic scaling
    }
    sum_sq_err += local_sum;
}
