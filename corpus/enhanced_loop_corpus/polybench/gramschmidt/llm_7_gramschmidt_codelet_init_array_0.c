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
for (i = 1; i < m; i += 2) { // Stride and offset to eliminate loop-carried dependencies
    for (j = 0; j < n; j++) {
        A[i][j] = (((double)(((i-1) * j) % m) / m) * 100) + 10; // Use previous row's index pattern
        Q[i][j] = 0.;
    }
}
for (i = 0; i < m; i += 2) { // Process even indices in separate pass to break WAW/RAW
    for (j = 0; j < n; j++) {
        A[i][j] = (((double)((i * j) % m) / m) * 100) + 10;
        Q[i][j] = 0.;
    }
}
}
