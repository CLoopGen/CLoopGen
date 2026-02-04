#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[1300][1300];
extern double B[1300][1300];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            A[i][j] = A[i-1][j] + ((double)i * (j + 2) + 2) / n;
            B[i][j] = B[i][j-1] + ((double)i * (j + 3) + 3) / n;
        }
    }
}
