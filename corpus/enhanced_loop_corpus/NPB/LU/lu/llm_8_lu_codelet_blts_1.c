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
            double sum_y = ldy[i][j][m][0] * v[i][j-1][k][0] + ldy[i][j][m][1] * v[i][j-1][k][1] + ldy[i][j][m][2] * v[i][j-1][k][2];
            double sum_x = ldx[i][j][m][0] * v[i-1][j][k][0] + ldx[i][j][m][1] * v[i-1][j][k][1] + ldx[i][j][m][2] * v[i-1][j][k][2];
            v[i][j][k][m] = v[i][j][k][m] - omega * (sum_y + sum_x);
        }
        for (m = 0; m < 3; m++) {
            tmat[m][0] = d[i][j][m][0];
            tmat[m][1] = d[i][j][m][1];
            tmat[m][2] = d[i][j][m][2];
            tmat[m][3] = d[i][j][m][3];
            tmat[m][4] = d[i][j][m][4];
        }
        tmp1 = 1.0 / tmat[0][0];
        for (m = 1; m < 3; m++) {
            tmp = tmp1 * tmat[m][0];
            tmat[m][1] -= tmp * tmat[0][1];
            tmat[m][2] -= tmp * tmat[0][2];
            v[i][j][k][m] -= v[i][j][k][0] * tmp;
        }
        if (tmat[1][1] != 0.0) {
            tmp1 = 1.0 / tmat[1][1];
            tmp = tmp1 * tmat[2][1];
            tmat[2][2] -= tmp * tmat[1][2];
            v[i][j][k][2] -= v[i][j][k][1] * tmp;
            v[i][j][k][2] /= tmat[2][2];
            v[i][j][k][1] = (v[i][j][k][1] - tmat[1][2] * v[i][j][k][2]) / tmat[1][1];
            v[i][j][k][0] = (v[i][j][k][0] - tmat[0][1] * v[i][j][k][1] - tmat[0][2] * v[i][j][k][2]) / tmat[0][0];
        }
    }
}
}
