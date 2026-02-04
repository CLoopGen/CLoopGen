#include <stdio.h>

extern int k;
extern double omega;
extern double v[64][65][65][5];
extern double tv[64][64][5];
extern double d[64][64][5][5];
extern double udx[64][64][5][5];
extern double udy[64][64][5][5];
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
for (i = iend; i >= ist; i--) {
    for (j = jend; j >= jst; j--) {
        double tv_local[5] = {0};
        for (m = 0; m < 5; m++) {
            tv_local[m] = tv[i][j][m] + omega * (
                udy[i][j][m][0] * v[i][j+1][k][0] + udx[i][j][m][0] * v[i+1][j][k][0] +
                udy[i][j][m][1] * v[i][j+1][k][1] + udx[i][j][m][1] * v[i+1][j][k][1] +
                udy[i][j][m][2] * v[i][j+1][k][2] + udx[i][j][m][2] * v[i+1][j][k][2] +
                udy[i][j][m][3] * v[i][j+1][k][3] + udx[i][j][m][3] * v[i+1][j][k][3] +
                udy[i][j][m][4] * v[i][j+1][k][4] + udx[i][j][m][4] * v[i+1][j][k][4]
            );
        }

        double tmat_local[5][5];
        for (int ii = 0; ii < 5; ii++) {
            for (int jj = 0; jj < 5; jj++) {
                tmat_local[ii][jj] = d[i][j][ii][jj];
            }
        }

        double temp;
        temp = 1.0 / tmat_local[0][0];
        for (int ii = 1; ii < 5; ii++) {
            double factor = temp * tmat_local[ii][0];
            tv_local[ii] -= tv_local[0] * factor;
            for (int jj = 1; jj < 5; jj++) {
                tmat_local[ii][jj] -= factor * tmat_local[0][jj];
            }
        }

        temp = 1.0 / tmat_local[1][1];
        for (int ii = 2; ii < 5; ii++) {
            double factor = temp * tmat_local[ii][1];
            tv_local[ii] -= tv_local[1] * factor;
            for (int jj = 2; jj < 5; jj++) {
                tmat_local[ii][jj] -= factor * tmat_local[1][jj];
            }
        }

        temp = 1.0 / tmat_local[2][2];
        for (int ii = 3; ii < 5; ii++) {
            double factor = temp * tmat_local[ii][2];
            tv_local[ii] -= tv_local[2] * factor;
            for (int jj = 3; jj < 5; jj++) {
                tmat_local[ii][jj] -= factor * tmat_local[2][jj];
            }
        }

        temp = 1.0 / tmat_local[3][3];
        double factor = temp * tmat_local[4][3];
        tv_local[4] -= tv_local[3] * factor;
        tmat_local[4][4] -= factor * tmat_local[3][4];

        tv_local[4] /= tmat_local[4][4];
        tv_local[3] = (tv_local[3] - tmat_local[3][4] * tv_local[4]) / tmat_local[3][3];
        tv_local[2] = (tv_local[2] - tmat_local[2][3] * tv_local[3] - tmat_local[2][4] * tv_local[4]) / tmat_local[2][2];
        tv_local[1] = (tv_local[1] - tmat_local[1][2] * tv_local[2] - tmat_local[1][3] * tv_local[3] - tmat_local[1][4] * tv_local[4]) / tmat_local[1][1];
        tv_local[0] = (tv_local[0] - tmat_local[0][1] * tv_local[1] - tmat_local[0][2] * tv_local[2] - tmat_local[0][3] * tv_local[3] - tmat_local[0][4] * tv_local[4]) / tmat_local[0][0];

        for (m = 0; m < 5; m++) {
            tv[i][j][m] = tv_local[m];
            v[i][j][k][m] -= tv_local[m];
        }
    }
}
}
