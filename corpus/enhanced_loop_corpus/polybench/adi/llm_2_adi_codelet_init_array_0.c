#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double u[1000][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to column-major (consecutive in j first)
    // This improves spatial locality when accessing u[i][j] by iterating j in the outer loop
    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++) {
            u[i][j] = (double)(i + n - j) / n;
        }
}
