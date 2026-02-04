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
int* index_map = (int*)__builtin_alloca(n * sizeof(int));
for (i = 0; i < n; i++) {
    index_map[i] = (n - 1 - i); // Reverse index mapping
}
for (i = 0; i < n; i++) {
    int idx = index_map[i];
    u1[idx] = i;
    u2[idx] = ((i + 1) / fn) / 2.;
    v1[idx] = ((i + 1) / fn) / 4.;
    v2[idx] = ((i + 1) / fn) / 6.;
    y[idx] = ((i + 1) / fn) / 8.;
    z[idx] = ((i + 1) / fn) / 9.;
    x[idx] = 0.;
    w[idx] = 0.;
    for (j = 0; j < n; j++) {
        int jdx = index_map[j];
        A[idx][jdx] = (double)((i * j) % n) / n;
    }
}
}
