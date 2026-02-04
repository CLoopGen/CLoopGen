#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int m;
extern double A[1200][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp;
for (i = 0; i < n; i++) {
    temp = (double)(i % n) / n;
    for (j = 0; j < m; j++)
        A[i][j] = temp * (j + 1);
}
}
