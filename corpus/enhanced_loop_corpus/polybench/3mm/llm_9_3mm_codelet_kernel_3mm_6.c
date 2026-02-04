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
for (i = 0; i < ni; i += 2)
    for (j = 0; j < nl; j += 2) {
        for (int di = 0; di < 2 && (i + di) < ni; ++di)
            for (int dj = 0; dj < 2 && (j + dj) < nl; ++dj) {
                int ii = i + di;
                int jj = j + dj;
                G[ii][jj] = 0.;
                for (k = 0; k < nj; ++k)
                    G[ii][jj] += E[ii][k] * F[k][jj];
            }
    }
}
