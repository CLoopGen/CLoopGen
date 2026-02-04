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
for (i = 0; i < nj && i < 500; i++)
    for (j = 0; j < nl; j++) {
        double sum1 = 0.0, sum2 = 0.0;
        int kmid = nm / 2;
        for (k = 0; k < kmid; ++k)
            sum1 += C[i][k] * D[k][j];
        for (k = kmid; k < nm; ++k)
            sum2 += C[i][k] * D[k][j];
        F[i][j] = sum1 + sum2;
    }
}
