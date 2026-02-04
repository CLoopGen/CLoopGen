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
    for (i = 0; i < (3 * 256); i++) {
        double diff;
        err = median[i] - (double)hist[i];
        diff = err * err;
        if (diff > 1e-9) {
            sum_sq_err += diff;
        }
    }
}
