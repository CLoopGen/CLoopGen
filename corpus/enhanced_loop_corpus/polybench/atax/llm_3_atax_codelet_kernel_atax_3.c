#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double A[1900][2100];
extern double x[2100];
extern double y[2100];
extern double tmp[1900];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    double sum = 0.0;
    double* Ai = A[i];
    double temp_val;
    for (j = 0; j < n; j++) {
        sum += Ai[j] * x[j];
    }
    tmp[i] = sum;
    for (j = 0; j < n; j++) {
        temp_val = Ai[j] * sum;
        y[j] = y[j] + temp_val;
    }
}
}
