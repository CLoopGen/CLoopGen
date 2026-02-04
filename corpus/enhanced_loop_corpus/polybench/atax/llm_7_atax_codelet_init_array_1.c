#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double A[1900][2100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < m; i++)
        for (j = 1; j < n; j++)
            A[i][j] = A[i-1][j-1] + (double)((i + j) % n) / (5 * m);
}
