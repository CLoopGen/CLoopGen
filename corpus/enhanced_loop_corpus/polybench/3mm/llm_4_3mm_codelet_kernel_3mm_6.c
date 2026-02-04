#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nj;
extern int nl;
extern double E[800][900];
extern double F[900][1100];
extern double G[800][1100];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ni; i++)
    for (j = 0; j < nl; j++) {
        G[i][j] = 0.;
        for (k = 0; k < nj; ++k) {
            if (E[i][k] == 0.0) continue;
            G[i][j] += E[i][k] * F[k][j];
        }
    }
}
