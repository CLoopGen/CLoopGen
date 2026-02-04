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
for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
        A[i][j] = (double)((i * j + 1) % n) / n;
        B[i][j] = (double)((i * j + 2) % m) / m;
    }

}
