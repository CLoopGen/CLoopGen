#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double C[1000][1200];
extern double B[1000][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < m; i++)
    for (j = 0; j < n; j++) {
        C[i][j] = (double)((i + j) % 100) / m;
        B[i][j] = (double)((n + i - j) % 100) / m;
    }

}
