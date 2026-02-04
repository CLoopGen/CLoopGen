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
for (i = 0; i < nr; i++)
    for (j = 0; j < nq; j++)
        for (k = 0; k < np; k += 2) {
            int k1 = k;
            int k2 = k + 1;
            if (k1 < np)
                A[i][j][k1] = (double)((i * j + k1) % np) / np;
            if (k2 < np)
                A[i][j][k2] = (double)((i * j + k2) % np) / np;
        }
}
