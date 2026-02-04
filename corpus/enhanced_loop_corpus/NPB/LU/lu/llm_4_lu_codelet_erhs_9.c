#include <stdio.h>

extern  int ny;
extern  int nz;
extern  int ist;
extern  int iend;
extern  int jst;
extern  int jend;
extern  double ty1;
extern  double ty2;
extern  double ty3;
extern  double dy1;
extern  double dy2;
extern  double dy3;
extern  double dy4;
extern  double dy5;
extern  double rsd[64][65][65][5];
extern  double frct[64][65][65][5];
extern  double flux[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;
extern int L2;
extern int jst1;
extern int jend1;
extern double dsspm;
extern double tmp;
extern double u21j;
extern double u31j;
extern double u41j;
extern double u51j;
extern double u21jm1;
extern double u31jm1;
extern double u41jm1;
extern double u51jm1;



void loop(){
for (i = ist; i <= iend; i++) {
    for (k = 1; k <= nz - 2; k++) {
        for (j = jst; j <= jend; j++) {
            for (m = 0; m < 5; m++) {
                frct[i][j][k][m] = frct[i][j][k][m] - ty2 * (flux[i][j + 1][k][m] - flux[i][j - 1][k][m]);
            }
        }
        for (j = jst; j <= L2; j++) {
            if (rsd[i][j][k][0] != 0.0 && rsd[i][j - 1][k][0] != 0.0) {
                tmp = 1. / rsd[i][j][k][0];
                u21j = tmp * rsd[i][j][k][1];
                u31j = tmp * rsd[i][j][k][2];
                u41j = tmp * rsd[i][j][k][3];
                u51j = tmp * rsd[i][j][k][4];
                tmp = 1. / rsd[i][j - 1][k][0];
                u21jm1 = tmp * rsd[i][j - 1][k][1];
                u31jm1 = tmp * rsd[i][j - 1][k][2];
                u41jm1 = tmp * rsd[i][j - 1][k][3];
                u51jm1 = tmp * rsd[i][j - 1][k][4];
                flux[i][j][k][1] = ty3 * (u21j - u21jm1);
                flux[i][j][k][2] = (4. / 3.) * ty3 * (u31j - u31jm1);
                flux[i][j][k][3] = ty3 * (u41j - u41jm1);
                flux[i][j][k][4] = 0.5 * (1. - 1.3999999999999999 * 1.3999999999999999) * ty3 * ((u21j * u21j + u31j * u31j + u41j * u41j) - (u21jm1 * u21jm1 + u31jm1 * u31jm1 + u41jm1 * u41jm1)) + (1. / 6.) * ty3 * (u31j * u31j - u31jm1 * u31jm1) + 1.3999999999999999 * 1.3999999999999999 * ty3 * (u51j - u51jm1);
            } else {
                for (m = 1; m <= 4; m++) {
                    flux[i][j][k][m] = 0.0;
                }
            }
        }
        for (j = jst; j <= jend; j++) {
            frct[i][j][k][0] = frct[i][j][k][0] + dy1 * ty1 * (rsd[i][j - 1][k][0] - 2. * rsd[i][j][k][0] + rsd[i][j + 1][k][0]);
            frct[i][j][k][1] = frct[i][j][k][1] + ty3 * 0.10000000000000001 * 1. * (flux[i][j + 1][k][1] - flux[i][j][k][1]) + dy2 * ty1 * (rsd[i][j - 1][k][1] - 2. * rsd[i][j][k][1] + rsd[i][j + 1][k][1]);
            frct[i][j][k][2] = frct[i][j][k][2] + ty3 * 0.10000000000000001 * 1. * (flux[i][j + 1][k][2] - flux[i][j][k][2]) + dy3 * ty1 * (rsd[i][j - 1][k][2] - 2. * rsd[i][j][k][2] + rsd[i][j + 1][k][2]);
            frct[i][j][k][3] = frct[i][j][k][3] + ty3 * 0.10000000000000001 * 1. * (flux[i][j + 1][k][3] - flux[i][j][k][3]) + dy4 * ty1 * (rsd[i][j - 1][k][3] - 2. * rsd[i][j][k][3] + rsd[i][j + 1][k][3]);
            frct[i][j][k][4] = frct[i][j][k][4] + ty3 * 0.10000000000000001 * 1. * (flux[i][j + 1][k][4] - flux[i][j][k][4]) + dy5 * ty1 * (rsd[i][j - 1][k][4] - 2. * rsd[i][j][k][4] + rsd[i][j + 1][k][4]);
        }
        for (m = 0; m < 5; m++) {
            if (ny > 6) {
                frct[i][1][k][m] = frct[i][1][k][m] - dsspm * (+5. * rsd[i][1][k][m] - 4. * rsd[i][2][k][m] + rsd[i][3][k][m]);
                frct[i][2][k][m] = frct[i][2][k][m] - dsspm * (-4. * rsd[i][1][k][m] + 6. * rsd[i][2][k][m] - 4. * rsd[i][3][k][m] + rsd[i][4][k][m]);
            }
        }
        jst1 = 3;
        jend1 = ny - 4;
        if (jst1 <= jend1) {
            for (j = jst1; j <= jend1; j++) {
                for (m = 0; m < 5; m++) {
                    frct[i][j][k][m] = frct[i][j][k][m] - dsspm * (rsd[i][j - 2][k][m] - 4. * rsd[i][j - 1][k][m] + 6. * rsd[i][j][k][m] - 4. * rsd[i][j + 1][k][m] + rsd[i][j + 2][k][m]);
                }
            }
        }
        for (m = 0; m < 5; m++) {
            if (ny > 6) {
                frct[i][ny - 3][k][m] = frct[i][ny - 3][k][m] - dsspm * (rsd[i][ny - 5][k][m] - 4. * rsd[i][ny - 4][k][m] + 6. * rsd[i][ny - 3][k][m] - 4. * rsd[i][ny - 2][k][m]);
                frct[i][ny - 2][k][m] = frct[i][ny - 2][k][m] - dsspm * (rsd[i][ny - 4][k][m] - 4. * rsd[i][ny - 3][k][m] + 5. * rsd[i][ny - 2][k][m]);
            }
        }
    }
}
}
