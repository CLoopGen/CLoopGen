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
        // First, update tv using spatial derivatives and v values
        for (m = 0; m < 5; m++) {
            tv[i][j][m] += omega * (
                udy[i][j][m][0] * v[i][j + 1][k][0] +
                udx[i][j][m][0] * v[i + 1][j][k][0] +
                udy[i][j][m][1] * v[i][j + 1][k][1] +
                udx[i][j][m][1] * v[i + 1][j][k][1] +
                udy[i][j][m][2] * v[i][j + 1][k][2] +
                udx[i][j][m][2] * v[i + 1][j][k][2] +
                udy[i][j][m][3] * v[i][j + 1][k][3] +
                udx[i][j][m][3] * v[i + 1][j][k][3] +
                udy[i][j][m][4] * v[i][j + 1][k][4] +
                udx[i][j][m][4] * v[i + 1][j][k][4]
            );
        }

        // Copy d[i][j] to tmat for LU factorization-like operations
        for (m = 0; m < 5; m++) {
            tmat[m][0] = d[i][j][m][0];
            tmat[m][1] = d[i][j][m][1];
            tmat[m][2] = d[i][j][m][2];
            tmat[m][3] = d[i][j][m][3];
            tmat[m][4] = d[i][j][m][4];
        }

        // Forward elimination with conditional skip if pivot is near zero
        tmp1 = tmat[0][0];
        if (tmp1 < 1e-15 && tmp1 > -1e-15) {
            goto skip_elimination;
        }
        tmp1 = 1.0 / tmp1;

        for (int row = 1; row < 5; row++) {
            tmp = tmp1 * tmat[row][0];
            tmat[row][1] -= tmp * tmat[0][1];
            tmat[row][2] -= tmp * tmat[0][2];
            tmat[row][3] -= tmp * tmat[0][3];
            tmat[row][4] -= tmp * tmat[0][4];
            tv[i][j][row] -= tv[i][j][0] * tmp;
        }

        tmp1 = tmat[1][1];
        if (tmp1 < 1e-15 && tmp1 > -1e-15) {
            goto skip_elimination;
        }
        tmp1 = 1.0 / tmp1;

        for (int row = 2; row < 5; row++) {
            tmp = tmp1 * tmat[row][1];
            tmat[row][2] -= tmp * tmat[1][2];
            tmat[row][3] -= tmp * tmat[1][3];
            tmat[row][4] -= tmp * tmat[1][4];
            tv[i][j][row] -= tv[i][j][1] * tmp;
        }

        tmp1 = tmat[2][2];
        if (tmp1 < 1e-15 && tmp1 > -1e-15) {
            goto skip_elimination;
        }
        tmp1 = 1.0 / tmp1;

        for (int row = 3; row < 5; row++) {
            tmp = tmp1 * tmat[row][2];
            tmat[row][3] -= tmp * tmat[2][3];
            tmat[row][4] -= tmp * tmat[2][4];
            tv[i][j][row] -= tv[i][j][2] * tmp;
        }

        tmp1 = tmat[3][3];
        if (tmp1 < 1e-15 && tmp1 > -1e-15) {
            goto skip_elimination;
        }
        tmp1 = 1.0 / tmp1;

        tmp = tmp1 * tmat[4][3];
        tmat[4][4] -= tmp * tmat[3][4];
        tv[i][j][4] -= tv[i][j][3] * tmp;

        // Back substitution
        tv[i][j][4] /= tmat[4][4];
        tv[i][j][3] = (tv[i][j][3] - tmat[3][4] * tv[i][j][4]) / tmat[3][3];
        tv[i][j][2] = (tv[i][j][2] - tmat[2][3] * tv[i][j][3] - tmat[2][4] * tv[i][j][4]) / tmat[2][2];
        tv[i][j][1] = (tv[i][j][1] - tmat[1][2] * tv[i][j][2] - tmat[1][3] * tv[i][j][3] - tmat[1][4] * tv[i][j][4]) / tmat[1][1];
        tv[i][j][0] = (tv[i][j][0] - tmat[0][1] * tv[i][j][1] - tmat[0][2] * tv[i][j][2] - tmat[0][3] * tv[i][j][3] - tmat[0][4] * tv[i][j][4]) / tmat[0][0];

skip_elimination:
        // Update v only if computation was not skipped
        v[i][j][k][0] -= tv[i][j][0];
        v[i][j][k][1] -= tv[i][j][1];
        v[i][j][k][2] -= tv[i][j][2];
        v[i][j][k][3] -= tv[i][j][3];
        v[i][j][k][4] -= tv[i][j][4];
    }
}
}
