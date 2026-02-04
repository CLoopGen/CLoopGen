#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double V3inv[289];
extern  double *fx;
extern double *c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computation to improve spatial locality
    // We precompute base indices to access fx with stride 2, storing in a temporary array for consecutive reads
    double fx_temp[17];
    for (int k = 0; k <= 16; k++) {
        fx_temp[k] = fx[k * 2];
    }
    for (i = 0; i <= 16; i++) {
        double sum = 0.0;
        const double* row_start = &V3inv[i * 17];
        for (j = 0; j <= 16; j++) {
            sum += row_start[j] * fx_temp[j];  // Consecutive access to V3inv row and fx_temp
        }
        c[i] = sum;
    }
}
