#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double A[1000][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    for (j = i + 1; j < m; j++)
        A[i][j] = -999;
    for (j = 0; j <= i; j++)
        A[i][j] = (double)((i + j + (int)A[i][i]) % 100) / m;
}
}
