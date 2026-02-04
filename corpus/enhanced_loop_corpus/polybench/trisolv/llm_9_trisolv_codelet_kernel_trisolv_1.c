#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double L[2000][2000];
extern double x[2000];
extern double b[2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    double sum = 0.0;
    for (j = 0; j < i; j += 4) {
        sum += L[i][j] * x[j];
        if (j + 1 < i) sum += L[i][j+1] * x[j+1];
        if (j + 2 < i) sum += L[i][j+2] * x[j+2];
        if (j + 3 < i) sum += L[i][j+3] * x[j+3];
    }
    x[i] = (b[i] - sum) / L[i][i];
}
}
