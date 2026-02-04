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
    // Variant 1: Strided memory access with stride of 2
    sum_sq_err = 0.0; // Reset accumulator as in original logic
    for (i = 0; i < (3 * 256); i += 2) {
        err = median[i] - (double)hist[i];
        sum_sq_err += err * err;
    }
    // Handle odd-sized last element if needed, but size is fixed (768), so even stride covers safe bounds
}
