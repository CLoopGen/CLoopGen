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
        for (m = 0; m < 5; m++) {
            tv[i][j][m] = tv[i][j][m] + omega * (
                udy[i][j][m][0] * v[i][j + 1][k][0] + 
                udx[i][j][m][0] * v[i + 1][j][k][0] + 
                udy[i][j][m][1] * v[i][j + 1][k][1] + 
                udx[i][j][m][1] * v[i + 1][j][k][1] + 
                udy[i][j][m][2] * v[i][j + 1][k][2] + 
                udx[i][j][m][2] * v[i + 1][j][k][2]
            );
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
            tv[i][j][m] -= tv[i][j][0] * tmp;
        }
        if (tmat[1][1] != 0.0) {
            tmp1 = 1.0 / tmat[1][1];
            tmp = tmp1 * tmat[2][1];
            tmat[2][2] -= tmp * tmat[1][2];
            tv[i][j][2] -= tv[i][j][1] * tmp;
        }
        if (tmat[2][2] != 0.0) {
            tv[i][j][2] /= tmat[2][2];
        }
        tv[i][j][1] = (tv[i][j][1] - tmat[1][2] * tv[i][j][2]) / tmat[1][1];
        tv[i][j][0] = (tv[i][j][0] - tmat[0][1] * tv[i][j][1] - tmat[0][2] * tv[i][j][2]) / tmat[0][0];
        for (m = 0; m < 3; m++) {
            v[i][j][k][m] -= tv[i][j][m];
        }
    }
}
}
