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
for (i = 0; i < n; i += 2) {
    for (j = 0; j < n; j++) {
        if (i + 1 < n) {
            A[i][j] += u1[i] * v1[j] + u2[i] * v2[j];
            A[i+1][j] += u1[i+1] * v1[j] + u2[i+1] * v2[j];
        } else {
            A[i][j] += u1[i] * v1[j] + u2[i] * v2[j];
        }
    }
}
}
