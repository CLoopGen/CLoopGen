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
    for (i = 0; i < (3 * 256); i += 4) {
        for (int k = 0; k < 4 && (i + k) < (3 * 256); k++) {
            int idx = i + k;
            err = median[idx] - (double)hist[idx];
            sum_sq_err += err * err;
        }
    }
}
