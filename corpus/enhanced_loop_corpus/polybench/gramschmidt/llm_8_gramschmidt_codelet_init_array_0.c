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
for (i = 0; i < m; i += 2)
    for (j = 0; j < n; j += 2) {
        double temp1 = (double)((i * j) % m);
        double temp2 = temp1 / m;
        double temp3 = temp2 * 100.0;
        double temp4 = temp3 + 10.0;
        A[i][j] = temp4;
        if (i + 1 < m) A[i+1][j] = temp4;
        if (j + 1 < n) A[i][j+1] = temp4;
        if (i + 1 < m && j + 1 < n) A[i+1][j+1] = temp4;
        Q[i][j] = 0.;
        if (i + 1 < m) Q[i+1][j] = 0.;
        if (j + 1 < n) Q[i][j+1] = 0.;
        if (i + 1 < m && j + 1 < n) Q[i+1][j+1] = 0.;
    }

}
