#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double u[1000][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < n; i += 2)
    for (j = 1; j < n; j += 2) {
        double temp1 = (double)(i + n - j);
        double temp2 = (double)(i - n + j);
        u[i][j] = (temp1 * temp2) / (n * n);
        u[i-1][j] = temp1 / n;
        u[i][j-1] = temp2 / n;
    }
}
