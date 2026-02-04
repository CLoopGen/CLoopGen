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
for (j = 0; j < 3; j++) {
    for (i = j * 256; i < (j + 1) * 256; i++) {
        err = median[i] - (double)hist[i];
        sum_sq_err += err * err;
    }
}
}
