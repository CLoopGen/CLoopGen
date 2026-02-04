#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern double u1[2000];
extern double v1[2000];
extern double u2[2000];
extern double v2[2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    double temp_u1 = u1[i];
    double temp_u2 = u2[i];
    for (j = 0; j < n; j++) {
        A[i][j] = A[i][j] + temp_u1 * v1[j] + temp_u2 * v2[j];
    }
}
}
