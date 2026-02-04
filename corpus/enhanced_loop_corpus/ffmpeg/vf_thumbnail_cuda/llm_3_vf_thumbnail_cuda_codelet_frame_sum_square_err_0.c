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
    // Variant 2: Reverse consecutive memory access
    sum_sq_err = 0.0;
    for (i = (3 * 256) - 1; i >= 0; i--) {
        err = median[i] - (double)hist[i];
        sum_sq_err += err * err;
    }
}
