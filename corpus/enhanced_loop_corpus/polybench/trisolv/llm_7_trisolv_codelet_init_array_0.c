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
    x[i] = -999;
    b[i] = (i > 0) ? b[i-1] + 1 : 0; // Introduce RAW dependency: b[i] depends on b[i-1]
    for (j = 0; j <= i; j++)
        L[i][j] = (double)(i + n - j + 1) * 2 / n;
}
}
