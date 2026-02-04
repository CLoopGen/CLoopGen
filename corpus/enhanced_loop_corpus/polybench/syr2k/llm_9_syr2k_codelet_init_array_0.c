#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int m;
extern double A[1200][1000];
extern double B[1200][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n * 2; i += 2)
    for (j = 0; j < m; j++) {
        int adjusted_i = i % n;
        A[adjusted_i][j] = (double)((adjusted_i * j + 1) % n) / n;
        if (i + 1 < n) {
            A[i + 1][j] = (double)(((i + 1) * j + 1) % n) / n;
        }
        B[adjusted_i][j] = (double)((adjusted_i * j + 2) % m) / m;
        if (i + 1 < n) {
            B[i + 1][j] = (double)(((i + 1) * j + 2) % m) / m;
        }
    }
}
