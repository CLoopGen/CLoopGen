#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to column-major (interchanged loops) for consecutive access in inner loop
    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++)
            A[i][j] = ((double)i * (j + 2) + 2) / n;
}
