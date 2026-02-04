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
        tmp1 = 1.0 / d[i][j][0][0];
        for (m = 0; m < 5; m++) {
            tmat[m][0] = d[i][j][m][0];
            tmat[m][1] = d[i][j][m][1];
            tmat[m][2] = d[i][j][m][2];
            tmat[m][3] = d[i][j][m][3];
            tmat[m][4] = d[i][j][m][4];
        }
        tv[i][j][0] = tv[i][j][0] + omega * (udy[i][j][0][0] * v[i][j + 1][k][0] + udx[i][j][0][0] * v[i + 1][j][k][0] +
                                             udy[i][j][0][1] * v[i][j + 1][k][1] + udx[i][j][0][1] * v[i + 1][j][k][1] +
                                             udy[i][j][0][2] * v[i][j + 1][k][2] + udx[i][j][0][2] * v[i + 1][j][k][2] +
                                             udy[i][j][0][3] * v[i][j + 1][k][3] + udx[i][j][0][3] * v[i + 1][j][k][3] +
                                             udy[i][j][0][4] * v[i][j + 1][k][4] + udx[i][j][0][4] * v[i + 1][j][k][4]);
        tv[i][j][1] = tv[i][j][1] + omega * (udy[i][j][1][0] * v[i][j + 1][k][0] + udx[i][j][1][0] * v[i + 1][j][k][0] +
                                             udy[i][j][1][1] * v[i][j + 1][k][1] + udx[i][j][1][1] * v[i + 1][j][k][1] +
                                             udy[i][j][1][2] * v[i][j + 1][k][2] + udx[i][j][1][2] * v[i + 1][j][k][2] +
                                             udy[i][j][1][3] * v[i][j + 1][k][3] + udx[i][j][1][3] * v[i + 1][j][k][3] +
                                             udy[i][j][1][4] * v[i][j + 1][k][4] + udx[i][j][1][4] * v[i + 1][j][k][4]);
        tv[i][j][2] = tv[i][j][2] + omega * (udy[i][j][2][0] * v[i][j + 1][k][0] + udx[i][j][2][0] * v[i + 1][j][k][0] +
                                             udy[i][j][2][1] * v[i][j + 1][k][1] + udx[i][j][2][1] * v[i + 1][j][k][1] +
                                             udy[i][j][2][2] * v[i][j + 1][k][2] + udx[i][j][2][2] * v[i + 1][j][k][2] +
                                             udy[i][j][2][3] * v[i][j + 1][k][3] + udx[i][j][2][3] * v[i + 1][j][k][3] +
                                             udy[i][j][2][4] * v[i][j + 1][k][4] + udx[i][j][2][4] * v[i + 1][j][k][4]);
        tv[i][j][3] = tv[i][j][3] + omega * (udy[i][j][3][0] * v[i][j + 1][k][0] + udx[i][j][3][0] * v[i + 1][j][k][0] +
                                             udy[i][j][3][1] * v[i][j + 1][k][1] + udx[i][j][3][1] * v[i + 1][j][k][1] +
                                             udy[i][j][3][2] * v[i][j + 1][k][2] + udx[i][j][3][2] * v[i + 1][j][k][2] +
                                             udy[i][j][3][3] * v[i][j + 1][k][3] + udx[i][j][3][3] * v[i + 1][j][k][3] +
                                             udy[i][j][3][4] * v[i][j + 1][k][4] + udx[i][j][3][4] * v[i + 1][j][k][4]);
        tv[i][j][4] = tv[i][j][4] + omega * (udy[i][j][4][0] * v[i][j + 1][k][0] + udx[i][j][4][0] * v[i + 1][j][k][0] +
                                             udy[i][j][4][1] * v[i][j + 1][k][1] + udx[i][j][4][1] * v[i + 1][j][k][1] +
                                             udy[i][j][4][2] * v[i][j + 1][k][2] + udx[i][j][4][2] * v[i + 1][j][k][2] +
                                             udy[i][j][4][3] * v[i][j + 1][k][3] + udx[i][j][4][3] * v[i + 1][j][k][3] +
                                             udy[i][j][4][4] * v[i][j + 1][k][4] + udx[i][j][4][4] * v[i + 1][j][k][4]);

        tmp = tmp1 * tmat[1][0];
        tmat[1][1] -= tmp * tmat[0][1];
        tmat[1][2] -= tmp * tmat[0][2];
        tmat[1][3] -= tmp * tmat[0][3];
        tmat[1][4] -= tmp * tmat[0][4];
        tv[i][j][1] -= tv[i][j][0] * tmp;

        tmp = tmp1 * tmat[2][0];
        tmat[2][1] -= tmp * tmat[0][1];
        tmat[2][2] -= tmp * tmat[0][2];
        tmat[2][3] -= tmp * tmat[0][3];
        tmat[2][4] -= tmp * tmat[0][4];
        tv[i][j][2] -= tv[i][j][0] * tmp;

        tmp = tmp1 * tmat[3][0];
        tmat[3][1] -= tmp * tmat[0][1];
        tmat[3][2] -= tmp * tmat[0][2];
        tmat[3][3] -= tmp * tmat[0][3];
        tmat[3][4] -= tmp * tmat[0][4];
        tv[i][j][3] -= tv[i][j][0] * tmp;

        tmp = tmp1 * tmat[4][0];
        tmat[4][1] -= tmp * tmat[0][1];
        tmat[4][2] -= tmp * tmat[0][2];
        tmat[4][3] -= tmp * tmat[0][3];
        tmat[4][4] -= tmp * tmat[0][4];
        tv[i][j][4] -= tv[i][j][0] * tmp;

        tmp1 = 1.0 / tmat[1][1];
        tmp = tmp1 * tmat[2][1];
        tmat[2][2] -= tmp * tmat[1][2];
        tmat[2][3] -= tmp * tmat[1][3];
        tmat[2][4] -= tmp * tmat[1][4];
        tv[i][j][2] -= tv[i][j][1] * tmp;

        tmp = tmp1 * tmat[3][1];
        tmat[3][2] -= tmp * tmat[1][2];
        tmat[3][3] -= tmp * tmat[1][3];
        tmat[3][4] -= tmp * tmat[1][4];
        tv[i][j][3] -= tv[i][j][1] * tmp;

        tmp = tmp1 * tmat[4][1];
        tmat[4][2] -= tmp * tmat[1][2];
        tmat[4][3] -= tmp * tmat[1][3];
        tmat[4][4] -= tmp * tmat[1][4];
        tv[i][j][4] -= tv[i][j][1] * tmp;

        tmp1 = 1.0 / tmat[2][2];
        tmp = tmp1 * tmat[3][2];
        tmat[3][3] -= tmp * tmat[2][3];
        tmat[3][4] -= tmp * tmat[2][4];
        tv[i][j][3] -= tv[i][j][2] * tmp;

        tmp = tmp1 * tmat[4][2];
        tmat[4][3] -= tmp * tmat[2][3];
        tmat[4][4] -= tmp * tmat[2][4];
        tv[i][j][4] -= tv[i][j][2] * tmp;

        tmp1 = 1.0 / tmat[3][3];
        tmp = tmp1 * tmat[4][3];
        tmat[4][4] -= tmp * tmat[3][4];
        tv[i][j][4] -= tv[i][j][3] * tmp;

        tv[i][j][4] /= tmat[4][4];
        tv[i][j][3] = (tv[i][j][3] - tmat[3][4] * tv[i][j][4]) / tmat[3][3];
        tv[i][j][2] = (tv[i][j][2] - tmat[2][3] * tv[i][j][3] - tmat[2][4] * tv[i][j][4]) / tmat[2][2];
        tv[i][j][1] = (tv[i][j][1] - tmat[1][2] * tv[i][j][2] - tmat[1][3] * tv[i][j][3] - tmat[1][4] * tv[i][j][4]) / tmat[1][1];
        tv[i][j][0] = (tv[i][j][0] - tmat[0][1] * tv[i][j][1] - tmat[0][2] * tv[i][j][2] - tmat[0][3] * tv[i][j][3] - tmat[0][4] * tv[i][j][4]) / tmat[0][0];

        v[i][j][k][0] -= tv[i][j][0];
        v[i][j][k][1] -= tv[i][j][1];
        v[i][j][k][2] -= tv[i][j][2];
        v[i][j][k][3] -= tv[i][j][3];
        v[i][j][k][4] -= tv[i][j][4];
    }
}
}
