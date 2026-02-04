#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int m;
extern int n;
extern int p;
extern double **A;
extern double **B;
extern double **C;
extern int Aj0;
extern int Bj0;
extern int Cj0;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) {
            temp = 0.0;
            for (k = 0; k < p; k++)
                temp += A[i][Aj0 + k] * B[k][Bj0 + j];
            C[i][Cj0 + j] += temp;
        }
}
