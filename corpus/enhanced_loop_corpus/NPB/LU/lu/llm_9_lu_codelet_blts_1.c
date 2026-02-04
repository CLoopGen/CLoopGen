#include <stdio.h>

extern int k;
extern double omega;
extern double v[64][65][65][5];
extern double ldy[64][64][5][5];
extern double ldx[64][64][5][5];
extern double d[64][64][5][5];
extern int ist;
extern int iend;
extern int jst;
extern int jend;
extern int i;
extern int j;
extern int m;
extern double tmp;
extern double tmp1;
extern double tmat[5][5];



void loop(){
for (i = ist + 1; i <= iend - 1; i += 2) {
    for (j = jst + 1; j <= jend - 1; j += 2) {
        for (int ii = 0; ii < 2; ii++) {
            int i_idx = i + ii;
            for (int jj = 0; jj < 2; jj++) {
                int j_idx = j + jj;
                for (m = 0; m < 5; m++) {
                    double term = 0.0;
                    for (int n = 0; n < 5; n++) {
                        term += ldy[i_idx][j_idx][m][n] * v[i_idx][j_idx - 1][k][n] +
                                ldx[i_idx][j_idx][m][n] * v[i_idx - 1][j_idx][k][n];
                    }
                    v[i_idx][j_idx][k][m] -= omega * term;
                }
                for (m = 0; m < 5; m++) {
                    for (int n = 0; n < 5; n++) {
                        tmat[m][n] = d[i_idx][j_idx][m][n];
                    }
                }
                for (int p = 0; p < 4; p++) {
                    tmp1 = 1.0 / tmat[p][p];
                    for (int m = p + 1; m < 5; m++) {
                        tmp = tmp1 * tmat[m][p];
                        for (int n = p + 1; n < 5; n++) {
                            tmat[m][n] -= tmp * tmat[p][n];
                        }
                        v[i_idx][j_idx][k][m] -= tmp * v[i_idx][j_idx][k][p];
                    }
                }
                for (int p = 4; p >= 0; p--) {
                    double sum = 0.0;
                    for (int n = p + 1; n < 5; n++) {
                        sum += tmat[p][n] * v[i_idx][j_idx][k][n];
                    }
                    v[i_idx][j_idx][k][p] = (v[i_idx][j_idx][k][p] - sum) / tmat[p][p];
                }
            }
        }
    }
}
}
