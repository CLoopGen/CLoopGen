#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2) {
    for (j = 0; j <= i; j++) {
        A[i][j] = (double)(-j % n) / n + 1;
        if (i + 1 < n)
            A[i+1][j] = (double)(-j % n) / n + 1;
    }
    for (j = i + 1; j < n; j++) {
        A[i][j] = 0;
        if (i + 1 < n)
            A[i+1][j] = 0;
    }
    A[i][i] = 1;
    if (i + 1 < n)
        A[i+1][i+1] = 1;
}
}
