#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern double u1[2000];
extern double v1[2000];
extern double u2[2000];
extern double v2[2000];
extern double w[2000];
extern double x[2000];
extern double y[2000];
extern double z[2000];
extern int i;
extern int j;
extern double fn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    u1[i] = i * i;
    u2[i] = ((i + 1) * (i + 1) / fn) / 2.;
    v1[i] = ((i + 1) * (i + 2) / fn) / 4.;
    v2[i] = ((i + 1) * (i + 3) / fn) / 6.;
    y[i] = ((i + 1) * (i + 4) / fn) / 8.;
    z[i] = ((i + 1) * (i + 5) / fn) / 9.;
    x[i] = 1.0;
    w[i] = 2.0;
    for (j = 0; j < n; j++) {
        double temp1 = (double)(i * j % n) / n;
        double temp2 = (double)(i + j) / n;
        A[i][j] = temp1 * temp2 + temp1 - temp2;
    }
}
}
