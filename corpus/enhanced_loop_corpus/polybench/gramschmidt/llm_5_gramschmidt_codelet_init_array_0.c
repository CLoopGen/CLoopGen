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
for (i = 0; i < m; i++)
    for (j = 0; j < n; j++) {
        if ((i + j) % 3 == 0) {
            A[i][j] = (((double)((i * j) % m) / m) * 100) + 10;
        } else {
            A[i][j] = 10.0;
        }
        Q[i][j] = 0.;
    }

}
