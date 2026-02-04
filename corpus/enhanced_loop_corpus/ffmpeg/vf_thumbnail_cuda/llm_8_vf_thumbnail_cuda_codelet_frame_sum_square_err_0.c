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
int j;
for (i = 0; i < (3 * 256); i += 2) {
    err = median[i] - (double)hist[i];
    sum_sq_err += err * err;
    if (i + 1 < (3 * 256)) {
        err = median[i+1] - (double)hist[i+1];
        sum_sq_err += err * err;
    }
}
}
