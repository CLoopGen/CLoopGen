#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double C[1000][1200];
extern double B[1000][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++)
    for (j = 0; j < n; j++) {
        double idx_sum = (double)(i + j);
        double idx_diff = (double)(n + i - j);
        C[i][j] = (idx_sum * idx_sum) / (m * m); // Increased arithmetic: square and divide
        B[i][j] = (idx_diff * idx_diff * idx_diff) / (m * m * m); // Cube instead of mod, more intense computation
    }
}
