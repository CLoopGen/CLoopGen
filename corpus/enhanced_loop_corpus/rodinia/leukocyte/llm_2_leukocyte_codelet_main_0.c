#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *crow;
extern int *ccol;
extern int pair_counter;
extern int x_result_len;
extern double *GICOV_spots;
extern double *G;
extern double *x_result;
extern double *y_result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element in a staggered manner)
    int stride = 2;
    for (i = 0; i < pair_counter; i += stride) {
        if ((crow[i] > 29) && (crow[i] < 328 - 110 + 39)) {
            x_result[x_result_len] = ccol[i];
            y_result[x_result_len] = crow[i] - 40;
            G[x_result_len] = GICOV_spots[i];
            x_result_len++;
        }
        // Handle the next element in the stride if within bounds
        int j = i + 1;
        if (j < pair_counter && (crow[j] > 29) && (crow[j] < 328 - 110 + 39)) {
            x_result[x_result_len] = ccol[j];
            y_result[x_result_len] = crow[j] - 40;
            G[x_result_len] = GICOV_spots[j];
            x_result_len++;
        }
    }
}
