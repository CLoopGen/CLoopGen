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
for (i = 0; i < n; i++) {
    for (j = 0; j < i; j++) {
        w = A[i][j];
        for (k = 0; k < j; k++) {
            if (A[i][k] == 0.0 || A[k][j] == 0.0) continue;
            w -= A[i][k] * A[k][j];
        }
        if (A[j][j] != 0.0) {
            A[i][j] = w / A[j][j];
        } else {
            A[i][j] = w;
        }
    }
    for (j = i; j < n; j++) {
        w = A[i][j];
        for (k = 0; k < i; k++) {
            if (A[i][k] == 0.0 || A[k][j] == 0.0) continue;
            w -= A[i][k] * A[k][j];
        }
        A[i][j] = w;
    }
}
}
