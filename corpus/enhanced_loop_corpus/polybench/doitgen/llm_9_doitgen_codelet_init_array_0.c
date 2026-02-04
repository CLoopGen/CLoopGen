#include <stdio.h>

#include <inttypes.h>

extern int nr;
extern int nq;
extern int np;
extern double A[150][140][160];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nr && i < 100; i++)
    for (j = 0; j < nq; j++)
        for (k = 0; k < np; k++)
            A[i][j][k] = (double)((i * (j + k) + (k * k)) % np) / np,
            A[i][j][np - k - 1] = (double)((i * (j + np - k - 1)) % np) / np;

}
