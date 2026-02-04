#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double A[2100][1900];
extern double s[1900];
extern double q[2100];
extern double p[1900];
extern double r[2100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    q[i] = 0.;
    double temp_q = 0.0;
    for (j = 0; j < m; j++) {
        s[j] += r[i] * A[i][j];
        temp_q += A[i][j] * p[j];
    }
    q[i] = temp_q;
}
}
