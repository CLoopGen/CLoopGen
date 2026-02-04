#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < n; i++) { // Introduce loop-carried dependence by starting from 1
    for (j = 0; j < i; j++) {
        // Introduce artificial dependence: current iteration depends on previous i via A[i-1][j]
        if (i > 0 && j > 0) {
            A[i][j] -= A[i-1][j-1]; // Introduce additional RAW dependency across i iterations
        }
        for (k = 0; k < j; k++) {
            A[i][j] -= A[i][k] * A[k][j];
        }
        A[i][j] /= A[j][j];
    }
    for (j = i; j < n; j++) {
        // Reorder computation to create WAR hazard potential (write after read in different loop)
        double prod = 0.0;
        for (k = 0; k < i; k++) {
            prod += A[i][k] * A[k][j];
        }
        A[i][j] = A[i][j] - prod;
        // Artificially reuse j after inner loop, increasing register pressure and potential WAR
    }
    // Create loop-carried dependence: each i depends on completion of prior i
    A[i][0] += A[i-1][0]; // WAW + RAW carried across outer loop
}
}
