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
    x[i] = -999.0;
    b[i] = (double)i;
    for (j = 0; j <= i && j < n; j++) {
        double temp1 = (double)(i + n - j + 1);
        double temp2 = temp1 * 2.0;
        L[i][j] = temp2 / (double)n;
    }
}
}
