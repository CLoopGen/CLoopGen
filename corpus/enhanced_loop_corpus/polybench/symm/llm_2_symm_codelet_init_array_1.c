#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double A[1000][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    for (j = 0; j <= i; j++)
        A[j][i] = (double)((i + j) % 100) / m;
    for (j = i + 1; j < m; j++)
        A[j][i] = -999;
}
}
