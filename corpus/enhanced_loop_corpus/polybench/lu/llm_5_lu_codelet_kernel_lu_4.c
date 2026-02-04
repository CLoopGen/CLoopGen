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
        for (k = 0; k < j; k++) {
            if (k % 2 == 0) {
                A[i][j] -= A[i][k] * A[k][j];
            } else {
                A[i][j] += A[i][k] * A[k][j]; // introduces conditional arithmetic
            }
        }
        if (A[j][j] != 0.0) {
            A[i][j] /= A[j][j];
        }
    }
    for (j = i; j < n; j++) {
        if (i == j) {
            continue; // skip diagonal update
        }
        for (k = 0; k < i; k++) {
            A[i][j] -= A[i][k] * A[k][j];
        }
    }
}
}
