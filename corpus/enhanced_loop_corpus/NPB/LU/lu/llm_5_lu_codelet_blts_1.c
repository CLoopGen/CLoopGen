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
            double sum = 0.0;
            for (int n = 0; n < 5; n++) {
                sum += ldy[i][j][m][n] * v[i][j - 1][k][n] + ldx[i][j][m][n] * v[i - 1][j][k][n];
            }
            v[i][j][k][m] -= omega * sum;
        }
        if (d[i][j][0][0] != 0.0) {
            for (m = 0; m < 5; m++) {
                tmat[m][0] = d[i][j][m][0];
                tmat[m][1] = d[i][j][m][1];
                tmat[m][2] = d[i][j][m][2];
                tmat[m][3] = d[i][j][m][3];
                tmat[m][4] = d[i][j][m][4];
            }
            tmp1 = 1.0 / tmat[0][0];
            for (int row = 1; row < 5; row++) {
                tmp = tmp1 * tmat[row][0];
                for (int col = 1; col < 5; col++) {
                    tmat[row][col] -= tmp * tmat[0][col];
                }
                v[i][j][k][row] -= v[i][j][k][0] * tmp;
            }
            if (tmat[1][1] != 0.0) {
                tmp1 = 1.0 / tmat[1][1];
                for (int row = 2; row < 5; row++) {
                    tmp = tmp1 * tmat[row][1];
                    for (int col = 2; col < 5; col++) {
                        tmat[row][col] -= tmp * tmat[1][col];
                    }
                    v[i][j][k][row] -= v[i][j][k][1] * tmp;
                }
                if (tmat[2][2] != 0.0) {
                    tmp1 = 1.0 / tmat[2][2];
                    for (int row = 3; row < 5; row++) {
                        tmp = tmp1 * tmat[row][2];
                        for (int col = 3; col < 5; col++) {
                            tmat[row][col] -= tmp * tmat[2][col];
                        }
                        v[i][j][k][row] -= v[i][j][k][2] * tmp;
                    }
                    if (tmat[3][3] != 0.0) {
                        tmp1 = 1.0 / tmat[3][3];
                        tmp = tmp1 * tmat[4][3];
                        tmat[4][4] -= tmp * tmat[3][4];
                        v[i][j][k][4] -= v[i][j][k][3] * tmp;

                        v[i][j][k][4] /= tmat[4][4];
                        v[i][j][k][3] = (v[i][j][k][3] - tmat[3][4] * v[i][j][k][4]) / tmat[3][3];
                        v[i][j][k][2] = (v[i][j][k][2] - tmat[2][3] * v[i][j][k][3] - tmat[2][4] * v[i][j][k][4]) / tmat[2][2];
                        v[i][j][k][1] = (v[i][j][k][1] - tmat[1][2] * v[i][j][k][2] - tmat[1][3] * v[i][j][k][3] - tmat[1][4] * v[i][j][k][4]) / tmat[1][1];
                        v[i][j][k][0] = (v[i][j][k][0] - tmat[0][1] * v[i][j][k][1] - tmat[0][2] * v[i][j][k][2] - tmat[0][3] * v[i][j][k][3] - tmat[0][4] * v[i][j][k][4]) / tmat[0][0];
                    }
                }
            }
        }
    }
}
}
