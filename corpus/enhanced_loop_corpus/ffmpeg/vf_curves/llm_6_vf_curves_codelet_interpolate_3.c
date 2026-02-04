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
for (i = 1; i < n - 1; i++) {
    double temp_h_prev = h[i - 1];
    double temp_h_curr = h[i];
    matrix[i][0] = temp_h_prev;
    matrix[i][1] = 2 * (temp_h_prev + temp_h_curr);
    matrix[i][2] = temp_h_curr;
}
}
