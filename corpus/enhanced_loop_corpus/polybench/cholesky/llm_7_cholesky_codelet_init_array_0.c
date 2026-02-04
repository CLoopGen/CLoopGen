#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < n; i++) {
    for (j = 0; j < n; j++) {
        if (j <= i) {
            A[i][j] = (double)(-j % n) / n + 1;
        } else {
            A[i][j] = A[i-1][j]; // Introduces loop-carried dependence (RAW): current iteration depends on previous i
        }
    }
    A[i][i] = 1; // Still ensures diagonal is 1, overrides any prior computation
}
// Note: i starts at 1 to allow dependence on i-1; first row (i=0) would need separate handling if required
}
