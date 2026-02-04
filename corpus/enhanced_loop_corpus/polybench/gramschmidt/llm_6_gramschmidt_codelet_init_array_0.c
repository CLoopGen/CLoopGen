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
for (i = 0; i < m; i++)
    for (j = 0; j < n; j++) {
        double temp = (((double)((i * j) % m) / m) * 100) + 10;
        A[i][j] = temp;
        Q[i][j] = temp - 10; // Introduces RAW dependency: Q[i][j] depends on A[i][j]'s computed value
    }
}
