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
    u1[i] = i;
    u2[i] = ((i + 1) / fn) / 2.;
    v1[i] = ((i + 1) / fn) / 4.;
    v2[i] = ((i + 1) / fn) / 6.;
    y[i] = ((i + 1) / fn) / 8.;
    z[i] = ((i + 1) / fn) / 9.;
    x[i] = 0.;
    w[i] = 0.;
}
for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
        A[i][j] = (double)((i * j) % n) / n;
    }
}
}
