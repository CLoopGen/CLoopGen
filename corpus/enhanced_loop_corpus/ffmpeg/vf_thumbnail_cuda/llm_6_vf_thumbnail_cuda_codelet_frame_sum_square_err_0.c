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
    double temp_sum = 0.0;
    for (i = 0; i < (3 * 256); i++) {
        err = median[i] - (double)hist[i];
        temp_sum += err * err;
    }
    sum_sq_err += temp_sum;
}
