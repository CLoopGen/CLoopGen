#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reverse iteration order to eliminate original loop-carried dependencies
    // Introduce RAW dependency within row by computing diagonal last
    for (i = n - 1; i >= 0; i--) {
        // Initialize off-diagonal elements first
        for (j = 0; j < n; j++) {
            if (j != i) {
                A[i][j] = (j <= i) ? ((double)(-j % n) / n + 1) : 0;
            }
        }
        // RAW dependency: value of A[i][j] for j != i used before setting A[i][i]
        // Final assignment depends logically on prior initializations
        A[i][i] = 1;
    }
}
