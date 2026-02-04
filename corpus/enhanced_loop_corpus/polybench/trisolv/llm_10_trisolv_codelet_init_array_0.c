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
int stride = 2;
for (i = 0; i < n; i += stride) {
    x[i] = -999.0;
    b[i] = (double)i;
    if (i + 1 < n) {
        x[i + 1] = -999.0;
        b[i + 1] = (double)(i + 1);
    }
    for (j = 0; j <= i; j++) {
        L[i][j] = (double)(i + n - j + 1) * 2.0 / (double)n;
        if (i + 1 < n && j <= i + 1) {
            L[i + 1][j] = (double)(i + 1 + n - j + 1) * 2.0 / (double)n;
        }
    }
}
// Handle odd-sized n with a cleanup pass if needed
for (; i < n; i++) {
    x[i] = -999.0;
    b[i] = (double)i;
    for (j = 0; j <= i; j++) {
        L[i][j] = (double)(i + n - j + 1) * 2.0 / (double)n;
    }
}
}
