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
for (i = ist; i <= iend; i++) {
    for (j = jst; j <= jend; j++) {
        for (m = 0; m < 5; m++) {
            v[i][j][k][m] = v[i][j][k][m] - omega * (ldy[i][j][m][0] * v[i][j - 1][k][0] + ldx[i][j][m][0] * v[i - 1][j][k][0] + ldy[i][j][m][1] * v[i][j - 1][k][1] + ldx[i][j][m][1] * v[i - 1][j][k][1] + ldy[i][j][m][2] * v[i][j - 1][k][2] + ldx[i][j][m][2] * v[i - 1][j][k][2] + ldy[i][j][m][3] * v[i][j - 1][k][3] + ldx[i][j][m][3] * v[i - 1][j][k][3] + ldy[i][j][m][4] * v[i][j - 1][k][4] + ldx[i][j][m][4] * v[i - 1][j][k][4]);
        }
        for (m = 0; m < 5; m++) {
            tmat[m][0] = d[i][j][m][0];
            tmat[m][1] = d[i][j][m][1];
            tmat[m][2] = d[i][j][m][2];
            tmat[m][3] = d[i][j][m][3];
            tmat[m][4] = d[i][j][m][4];
        }
        for (int n = 1; n < 5; n++) {
            tmp1 = 1.0 / tmat[n-1][n-1];
            for (int p = n; p < 5; p++) {
                tmp = tmp1 * tmat[p][n-1];
                for (int q = n; q < 5; q++) {
                    tmat[p][q] = tmat[p][q] - tmp * tmat[n-1][q];
                }
                v[i][j][k][p] = v[i][j][k][p] - v[i][j][k][n-1] * tmp;
            }
        }
        for (int n = 4; n >= 0; n--) {
            double sum = 0.0;
            for (int p = n + 1; p < 5; p++) {
                sum += tmat[n][p] * v[i][j][k][p];
            }
            v[i][j][k][n] = (v[i][j][k][n] - sum) / tmat[n][n];
        }
    }
}
}
