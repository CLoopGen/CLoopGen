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
        // Change memory access pattern to favor spatial locality by reordering computation
        // and accessing v[i][j][k][m] in a more cache-friendly manner via direct indexing with stride reduction.
        double tv_local[5] = {0};
        for (m = 0; m < 5; m++) {
            tv_local[m] = tv[i][j][m];
        }
        for (m = 0; m < 5; m++) {
            tv_local[m] += omega * (
                udy[i][j][m][0] * v[i][j+1][k][0] +
                udx[i][j][m][0] * v[i+1][j][k][0] +
                udy[i][j][m][1] * v[i][j+1][k][1] +
                udx[i][j][m][1] * v[i+1][j][k][1] +
                udy[i][j][m][2] * v[i][j+1][k][2] +
                udx[i][j][m][2] * v[i+1][j][k][2] +
                udy[i][j][m][3] * v[i][j+1][k][3] +
                udx[i][j][m][3] * v[i+1][j][k][3] +
                udy[i][j][m][4] * v[i][j+1][k][4] +
                udx[i][j][m][4] * v[i+1][j][k][4]
            );
        }
        double tmat_local[5][5];
        for (int n = 0; n < 5; n++) {
            for (int p = 0; p < 5; p++) {
                tmat_local[n][p] = d[i][j][n][p];
            }
        }
        tmp1 = 1.0 / tmat_local[0][0];
        for (int n = 1; n < 5; n++) {
            tmp = tmp1 * tmat_local[n][0];
            for (int p = 1; p < 5; p++) {
                tmat_local[n][p] -= tmp * tmat_local[0][p];
            }
            tv_local[n] -= tv_local[0] * tmp;
        }
        tmp1 = 1.0 / tmat_local[1][1];
        for (int n = 2; n < 5; n++) {
            tmp = tmp1 * tmat_local[n][1];
            for (int p = 2; p < 5; p++) {
                tmat_local[n][p] -= tmp * tmat_local[1][p];
            }
            tv_local[n] -= tv_local[1] * tmp;
        }
        tmp1 = 1.0 / tmat_local[2][2];
        for (int n = 3; n < 5; n++) {
            tmp = tmp1 * tmat_local[n][2];
            for (int p = 3; p < 5; p++) {
                tmat_local[n][p] -= tmp * tmat_local[2][p];
            }
            tv_local[n] -= tv_local[2] * tmp;
        }
        tmp1 = 1.0 / tmat_local[3][3];
        tmp = tmp1 * tmat_local[4][3];
        tmat_local[4][4] -= tmp * tmat_local[3][4];
        tv_local[4] -= tv_local[3] * tmp;

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
