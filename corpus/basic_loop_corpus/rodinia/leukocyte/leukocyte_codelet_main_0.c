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
for (i = 0; i < pair_counter; i++) {
    if ((crow[i] > 29) && (crow[i] < 328 - 110 + 39)) {
        x_result[x_result_len] = ccol[i];
        y_result[x_result_len] = crow[i] - 40;
        G[x_result_len] = GICOV_spots[i];
        x_result_len++;
    }
}

}
