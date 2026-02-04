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
    for (j = 0; j < m; j += 2) {
        double temp1 = (double)((i * j + 1) % n) / n;
        double temp2 = (double)((i * (j + 1) + 1) % n) / n;
        A[i][j] = temp1;
        if (j + 1 < m)
            A[i][j + 1] = temp2;
    }
}
