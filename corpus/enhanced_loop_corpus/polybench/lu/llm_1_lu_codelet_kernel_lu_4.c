#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    for (j = 0; j < i; j++) {
        for (int jj = 0; jj <= j; jj++) { // Increased depth by splitting logic with auxiliary index
            if (jj == j && j > 0) {
                A[i][j] /= A[j][j];
            } else {
                for (k = 0; k < jj; k++) {
                    A[i][jj] -= A[i][k] * A[k][jj];
                }
            }
        }
    }
    for (j = i; j < n; j++) {
        for (k = 0; k < i; k++) {
            A[i][j] -= A[i][k] * A[k][j];
        }
    }
}
}
