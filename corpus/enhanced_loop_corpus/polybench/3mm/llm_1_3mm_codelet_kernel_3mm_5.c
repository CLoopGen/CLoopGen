#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nl;
extern int nm;
extern double F[900][1100];
extern double C[900][1200];
extern double D[1200][1100];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nj && nm > 0; i++)
    for (k = 0; k < nm; ++k)
        for (j = 0; j < nl; j++)
            F[i][j] = (k == 0 ? 0. : F[i][j]) + C[i][k] * D[k][j];
}
