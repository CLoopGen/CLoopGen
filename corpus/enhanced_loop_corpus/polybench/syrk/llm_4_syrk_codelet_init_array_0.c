#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int m;
extern double A[1200][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
        if (i == 0 || j == 0)
            A[i][j] = 1.0;
        else
            A[i][j] = (double)((i * j + 1) % n) / n;
    }
}
