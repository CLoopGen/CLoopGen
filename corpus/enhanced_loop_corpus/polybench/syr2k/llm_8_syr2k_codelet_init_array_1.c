#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int m;
extern double C[1200][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
        double temp1 = (double)(i * j + 3) / m;
        double temp2 = (double)(i + j) / n;
        C[i][j] = temp1 + temp2;
    }
}
