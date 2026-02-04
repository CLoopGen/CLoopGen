#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double A[1000][1200];
extern double Q[1000][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Introduce strided memory access with stride of 2 to simulate non-consecutive access, processing every second element
    for (i = 0; i < m; i += 2)
        for (j = 0; j < n; j += 2) {
            A[i][j] = (((double)((i * j) % m) / m) * 100) + 10;
            Q[i][j] = 0.;
            // Fill skipped elements if within bounds to maintain correctness
            if (j + 1 < n) {
                A[i][j+1] = (((double)((i * (j+1)) % m) / m) * 100) + 10;
                Q[i][j+1] = 0.;
            }
            if (i + 1 < m) {
                A[i+1][j] = (((double)(((i+1) * j) % m) / m) * 100) + 10;
                Q[i+1][j] = 0.;
                if (j + 1 < n) {
                    A[i+1][j+1] = (((double)(((i+1) * (j+1)) % m) / m) * 100) + 10;
                    Q[i+1][j+1] = 0.;
                }
            }
        }
}
