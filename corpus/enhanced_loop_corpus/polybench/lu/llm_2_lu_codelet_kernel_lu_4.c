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
        double *Ai = A[i];
        double *Aj = A[j];
        double temp = 0.0;
        for (k = 0; k < j; k += 2) {
            if (k + 1 < j) {
                temp += Ai[k] * Aj[k] + Ai[k+1] * Aj[k+1];
            } else {
                temp += Ai[k] * Aj[k];
            }
        }
        A[i][j] -= temp;
        A[i][j] /= A[j][j];
    }
    for (j = i; j < n; j++) {
        double *Ai = A[i];
        double temp = 0.0;
        for (k = 0; k < i; k += 2) {
            if (k + 1 < i) {
                temp += Ai[k] * A[k][j] + Ai[k+1] * A[k+1][j];
            } else {
                temp += Ai[k] * A[k][j];
            }
        }
        A[i][j] -= temp;
    }
}
}
