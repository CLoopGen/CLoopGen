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
if (n > 2) {
    matrix[1][0] = h[0];
    matrix[1][1] = 2 * (h[0] + h[1]);
    matrix[1][2] = h[1];
}
for (i = 2; i < n - 1; i++) {
    matrix[i][0] = h[i - 1];
    matrix[i][1] = 2 * (h[i - 1] + h[i]);
    matrix[i][2] = h[i];
    matrix[i-1][1] += matrix[i][0]; // Introduce WAW and RAW dependency: reuse of matrix[i-1][1] with update depending on current iteration
}
}
