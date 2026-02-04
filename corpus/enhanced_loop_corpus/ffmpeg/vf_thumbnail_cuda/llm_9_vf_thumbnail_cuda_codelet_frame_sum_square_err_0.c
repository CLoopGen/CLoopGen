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
double err1, err2, err3;
for (i = 0; i < (256); i++) {
    err1 = median[i] - (double)hist[i];
    err2 = median[i + 256] - (double)hist[i + 256];
    err3 = median[i + 512] - (double)hist[i + 512];
    sum_sq_err += err1 * err1 + err2 * err2 + err3 * err3;
}
}
