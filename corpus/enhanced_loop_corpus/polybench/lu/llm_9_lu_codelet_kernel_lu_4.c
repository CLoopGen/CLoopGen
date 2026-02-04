#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2) {
    if (i + 1 < n) {
        for (j = 0; j < i + 1; j++) {
            for (k = 0; k < j; k++) {
                A[i][j] -= A[i][k] * A[k][j];
                A[i+1][j] -= A[i+1][k] * A[k][j];
            }
            if (j < i) {
                A[i][j] /= A[j][j];
                A[i+1][j] /= A[j][j];
            }
        }
        for (j = i; j < n; j++) {
            for (k = 0; k < i; k++) {
                A[i][j] -= A[i][k] * A[k][j];
                A[i+1][j] -= A[i+1][k] * A[k][j];
            }
        }
    } else {
        for (j = 0; j < i; j++) {
            for (k = 0; k < j; k++) {
                A[i][j] -= A[i][k] * A[k][j];
            }
            A[i][j] /= A[j][j];
        }
        for (j = i; j < n; j++) {
            for (k = 0; k < i; k++) {
                A[i][j] -= A[i][k] * A[k][j];
            }
        }
    }
}
}
