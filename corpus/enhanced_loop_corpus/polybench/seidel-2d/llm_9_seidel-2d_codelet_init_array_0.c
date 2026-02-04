#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
        double temp1 = (double)(i + 1);
        double temp2 = (double)(j + 2);
        double temp3 = temp1 * temp2;
        double temp4 = temp3 + 3.0;
        double temp5 = temp4 * temp4; 
        A[i][j] = (temp5 - temp3) / ((double)n * n);
    }
}
