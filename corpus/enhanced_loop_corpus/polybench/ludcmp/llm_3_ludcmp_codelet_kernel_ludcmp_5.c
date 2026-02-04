#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;
extern int k;
extern double w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double (*Ap)[2000] = (double (*)[2000])((uintptr_t)A);
for (i = 0; i < n; i++) {
    for (j = 0; j < i; j++) {
        w = Ap[i][j];
        for (k = 0; k < j; k += 2) {
            w -= Ap[i][k] * Ap[k][j];
            if (k + 1 < j) {
                w -= Ap[i][k+1] * Ap[k+1][j];
            }
        }
        Ap[i][j] = w / Ap[j][j];
    }
    for (j = i; j < n; j++) {
        w = Ap[i][j];
        for (k = 0; k < i; k += 2) {
            w -= Ap[i][k] * Ap[k][j];
            if (k + 1 < i) {
                w -= Ap[i][k+1] * Ap[k+1][j];
            }
        }
        Ap[i][j] = w;
    }
}
}
