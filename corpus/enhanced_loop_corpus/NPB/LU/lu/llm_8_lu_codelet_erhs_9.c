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
        }
        for (j = jst; j <= jend; j++) {
            double rsd_jm1_0 = rsd[i][j - 1][k][0], rsd_j_0 = rsd[i][j][k][0], rsd_jp1_0 = rsd[i][j + 1][k][0];
            frct[i][j][k][0] += dy1 * ty1 * (rsd_jm1_0 - 2. * rsd_j_0 + rsd_jp1_0);

            double rsd_jm1_1 = rsd[i][j - 1][k][1], rsd_j_1 = rsd[i][j][k][1], rsd_jp1_1 = rsd[i][j + 1][k][1];
            double flux_diff_1 = flux[i][j + 1][k][1] - flux[i][j][k][1];
            frct[i][j][k][1] += ty3 * 0.1 * flux_diff_1 + dy2 * ty1 * (rsd_jm1_1 - 2. * rsd_j_1 + rsd_jp1_1);

            double rsd_jm1_2 = rsd[i][j - 1][k][2], rsd_j_2 = rsd[i][j][k][2], rsd_jp1_2 = rsd[i][j + 1][k][2];
            double flux_diff_2 = flux[i][j + 1][k][2] - flux[i][j][k][2];
            frct[i][j][k][2] += ty3 * 0.1 * flux_diff_2 + dy3 * ty1 * (rsd_jm1_2 - 2. * rsd_j_2 + rsd_jp1_2);

            double rsd_jm1_3 = rsd[i][j - 1][k][3], rsd_j_3 = rsd[i][j][k][3], rsd_jp1_3 = rsd[i][j + 1][k][3];
            double flux_diff_3 = flux[i][j + 1][k][3] - flux[i][j][k][3];
            frct[i][j][k][3] += ty3 * 0.1 * flux_diff_3 + dy4 * ty1 * (rsd_jm1_3 - 2. * rsd_j_3 + rsd_jp1_3);

            double rsd_jm1_4 = rsd[i][j - 1][k][4], rsd_j_4 = rsd[i][j][k][4], rsd_jp1_4 = rsd[i][j + 1][k][4];
            double flux_diff_4 = flux[i][j + 1][k][4] - flux[i][j][k][4];
            frct[i][j][k][4] += ty3 * 0.1 * flux_diff_4 + dy5 * ty1 * (rsd_jm1_4 - 2. * rsd_j_4 + rsd_jp1_4);
        }
        jst1 = 3;
        jend1 = ny - 4;
        for (j = jst1; j <= jend1; j += 2) {
            for (m = 0; m < 5; m++) {
                double coeff = dsspm * (rsd[i][j - 2][k][m] - 4. * rsd[i][j - 1][k][m] + 6. * rsd[i][j][k][m] - 4. * rsd[i][j + 1][k][m] + rsd[i][j + 2][k][m]);
                frct[i][j][k][m] -= coeff;
                if (j + 1 <= jend1) {
                    double coeff_next = dsspm * (rsd[i][j + 1 - 2][k][m] - 4. * rsd[i][j + 1 - 1][k][m] + 6. * rsd[i][j + 1][k][m] - 4. * rsd[i][j + 1 + 1][k][m] + rsd[i][j + 1 + 2][k][m]);
                    frct[i][j + 1][k][m] -= coeff_next;
                }
            }
        }
        for (m = 0; m < 5; m++) {
            frct[i][1][k][m] -= dsspm * (+5. * rsd[i][1][k][m] - 4. * rsd[i][2][k][m] + rsd[i][3][k][m]);
            frct[i][2][k][m] -= dsspm * (-4. * rsd[i][1][k][m] + 6. * rsd[i][2][k][m] - 4. * rsd[i][3][k][m] + rsd[i][4][k][m]);
            frct[i][ny - 3][k][m] -= dsspm * (rsd[i][ny - 5][k][m] - 4. * rsd[i][ny - 4][k][m] + 6. * rsd[i][ny - 3][k][m] - 4. * rsd[i][ny - 2][k][m]);
            frct[i][ny - 2][k][m] -= dsspm * (rsd[i][ny - 4][k][m] - 4. * rsd[i][ny - 3][k][m] + 5. * rsd[i][ny - 2][k][m]);
        }
    }
}
}
