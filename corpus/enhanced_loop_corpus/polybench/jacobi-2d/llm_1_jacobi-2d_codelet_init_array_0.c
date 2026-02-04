#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[1300][1300];
extern double B[1300][1300];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    A[i][0] = ((double)i * (0 + 2) + 2) / n;
    B[i][0] = ((double)i * (0 + 3) + 3) / n;
    for (j = 1; j < n; j++) {
        A[i][j] = ((double)i * (j + 2) + 2) / n;
        B[i][j] = ((double)i * (j + 3) + 3) / n;
    }
}
}
