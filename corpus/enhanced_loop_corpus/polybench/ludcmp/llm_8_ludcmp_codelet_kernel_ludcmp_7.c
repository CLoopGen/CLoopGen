#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern double x[2000];
extern double y[2000];
extern int i;
extern int j;
extern double w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = n - 1; i >= 0; i -= 2) {
        if (i == 0) {
            w = y[i];
            for (j = i + 1; j < n; j++)
                w -= A[i][j] * x[j];
            x[i] = w / A[i][i];
            break;
        }
        double w1 = y[i];
        double w2 = y[i-1];
        for (j = i + 1; j < n; j++) {
            w1 -= A[i][j] * x[j];
            if (j > i) 
                w2 -= A[i-1][j] * x[j];
        }
        x[i] = w1 / A[i][i];
        x[i-1] = w2 / A[i-1][i-1];
    }
}
