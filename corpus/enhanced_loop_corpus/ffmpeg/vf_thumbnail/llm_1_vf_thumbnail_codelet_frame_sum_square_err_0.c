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
for (i = 0; i < 256; i++) {
    err = median[i] - (double)hist[i];
    sum_sq_err += err * err;
    err = median[i + 256] - (double)hist[i + 256];
    sum_sq_err += err * err;
    err = median[i + 512] - (double)hist[i + 512];
    sum_sq_err += err * err;
}
}
