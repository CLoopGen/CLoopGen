#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x1[2000];
extern double y_1[2000];
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2) {
    for (j = 0; j < n; j++) {
        if (i < n) {
            x1[i] += A[i][j] * y_1[j];
        }
        if (i + 1 < n) {
            x1[i+1] += A[i+1][j] * y_1[j];
        }
    }
}
}
