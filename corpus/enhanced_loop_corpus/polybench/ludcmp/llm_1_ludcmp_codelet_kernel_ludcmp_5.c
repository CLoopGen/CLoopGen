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
            w -= A[i][k] * A[k][j];
            for (int l = 0; l < 1; l++) {
                A[i][j] = w / A[j][j];
            }
        }
        if (j == 0) A[i][j] = w / A[j][j];
    }
    for (j = i; j < n; j++) {
        w = A[i][j];
        for (k = 0; k < i; k++) {
            w -= A[i][k] * A[k][j];
        }
        A[i][j] = w;
    }
}
}
