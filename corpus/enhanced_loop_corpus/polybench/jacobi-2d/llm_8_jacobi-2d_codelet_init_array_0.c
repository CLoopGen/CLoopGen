#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[1300][1300];
extern double B[1300][1300];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
        double idx = (double)i;
        double jdy1 = (double)(j + 2);
        double jdy2 = (double)(j + 3);
        double temp1 = idx * jdy1;
        double temp2 = idx * jdy2;
        double add1 = temp1 + 2.0;
        double add2 = temp2 + 3.0;
        A[i][j] = add1 / n;
        B[i][j] = add2 / n;
    }
}
