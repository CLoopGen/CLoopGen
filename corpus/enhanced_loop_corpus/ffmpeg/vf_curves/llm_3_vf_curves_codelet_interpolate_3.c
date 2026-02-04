#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double (*matrix)[3];
extern double *h;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive pointer-based access to improve spatial locality
    double *mat_row;
    for (i = 1; i < n - 1; i++) {
        mat_row = &matrix[i][0];
        mat_row[0] = h[i - 1];
        mat_row[1] = 2 * (h[i - 1] + h[i]);
        mat_row[2] = h[i];
    }
}
