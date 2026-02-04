#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nj;
extern int nl;
extern double beta;
extern double tmp[800][900];
extern double C[900][1200];
extern double D[800][1200];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ni; i += 2)
    for (j = 0; j < nl; j += 2) {
        for (int ii = 0; ii < 2 && (i + ii) < ni; ++ii)
            for (int jj = 0; jj < 2 && (j + jj) < nl; ++jj) {
                int idx_i = i + ii;
                int idx_j = j + jj;
                D[idx_i][idx_j] *= beta;
                for (k = 0; k < nj; ++k)
                    D[idx_i][idx_j] += tmp[idx_i][k] * C[k][idx_j];
            }
    }
}
