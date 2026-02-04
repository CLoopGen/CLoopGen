#include <stdio.h>

extern  int nz;
extern  int ist;
extern  int iend;
extern  int jst;
extern  int jend;
extern  double tz1;
extern  double tz2;
extern  double tz3;
extern  double dz1;
extern  double dz2;
extern  double dz3;
extern  double dz4;
extern  double dz5;
extern  double rsd[64][65][65][5];
extern  double frct[64][65][65][5];
extern  double flux[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;
extern double dsspm;
extern double q;
extern double u41;
extern double tmp;
extern double u21k;
extern double u31k;
extern double u41k;
extern double u51k;
extern double u21km1;
extern double u31km1;
extern double u41km1;
extern double u51km1;



void loop(){
for (i = ist; i <= iend; i++) {
    for (j = jst; j <= jend; j++) {
        for (k = 0; k <= nz - 1; k += 2) {
            for (int offset = 0; offset < 2 && k + offset <= nz - 1; offset++) {
                int idx = k + offset;
                flux[i][j][idx][0] = rsd[i][j][idx][3];
                u41 = rsd[i][j][idx][3] / rsd[i][j][idx][0];
                q = 0.5 * (rsd[i][j][idx][1] * rsd[i][j][idx][1] + rsd[i][j][idx][2] * rsd[i][j][idx][2] + rsd[i][j][idx][3] * rsd[i][j][idx][3]) / rsd[i][j][idx][0];
                flux[i][j][idx][1] = rsd[i][j][idx][1] * u41;
                flux[i][j][idx][2] = rsd[i][j][idx][2] * u41;
                flux[i][j][idx][3] = rsd[i][j][idx][3] * u41 + 0.40000000000000002 * (rsd[i][j][idx][4] - q);
                flux[i][j][idx][4] = (1.3999999999999999 * rsd[i][j][idx][4] - 0.40000000000000002 * q) * u41;
            }
        }
        for (k = 1; k <= nz - 2; k += 2) {
            for (int offset = 0; offset < 2 && k + offset <= nz - 2; offset++) {
                int idx = k + offset;
                for (m = 0; m < 5; m++) {
                    frct[i][j][idx][m] = frct[i][j][idx][m] - tz2 * (flux[i][j][idx + 1][m] - flux[i][j][idx - 1][m]);
                }
            }
        }
        for (k = 1; k <= nz - 1; k += 2) {
            for (int offset = 0; offset < 2 && k + offset <= nz - 1; offset++) {
                int idx = k + offset;
                int km1 = idx - 1;
                tmp = 1. / rsd[i][j][idx][0];
                u21k = tmp * rsd[i][j][idx][1];
                u31k = tmp * rsd[i][j][idx][2];
                u41k = tmp * rsd[i][j][idx][3];
                u51k = tmp * rsd[i][j][idx][4];
                tmp = 1. / rsd[i][j][km1][0];
                u21km1 = tmp * rsd[i][j][km1][1];
                u31km1 = tmp * rsd[i][j][km1][2];
                u41km1 = tmp * rsd[i][j][km1][3];
                u51km1 = tmp * rsd[i][j][km1][4];
                flux[i][j][idx][1] = tz3 * (u21k - u21km1);
                flux[i][j][idx][2] = tz3 * (u31k - u31km1);
                flux[i][j][idx][3] = (4. / 3.) * tz3 * (u41k - u41km1);
                flux[i][j][idx][4] = 0.5 * (1. - 1.3999999999999999 * 1.3999999999999999) * tz3 * ((u21k * u21k + u31k * u31k + u41k * u41k) - (u21km1 * u21km1 + u31km1 * u31km1 + u41km1 * u41km1)) + (1. / 6.) * tz3 * (u41k * u41k - u41km1 * u41km1) + 1.3999999999999999 * 1.3999999999999999 * tz3 * (u51k - u51km1);
            }
        }
        for (k = 1; k <= nz - 2; k += 2) {
            for (int offset = 0; offset < 2 && k + offset <= nz - 2; offset++) {
                int idx = k + offset;
                int kp1 = idx + 1;
                int km1 = idx - 1;
                frct[i][j][idx][0] = frct[i][j][idx][0] + dz1 * tz1 * (rsd[i][j][kp1][0] - 2. * rsd[i][j][idx][0] + rsd[i][j][km1][0]);
                frct[i][j][idx][1] = frct[i][j][idx][1] + tz3 * 0.10000000000000001 * 1. * (flux[i][j][kp1][1] - flux[i][j][idx][1]) + dz2 * tz1 * (rsd[i][j][kp1][1] - 2. * rsd[i][j][idx][1] + rsd[i][j][km1][1]);
                frct[i][j][idx][2] = frct[i][j][idx][2] + tz3 * 0.10000000000000001 * 1. * (flux[i][j][kp1][2] - flux[i][j][idx][2]) + dz3 * tz1 * (rsd[i][j][kp1][2] - 2. * rsd[i][j][idx][2] + rsd[i][j][km1][2]);
                frct[i][j][idx][3] = frct[i][j][idx][3] + tz3 * 0.10000000000000001 * 1. * (flux[i][j][kp1][3] - flux[i][j][idx][3]) + dz4 * tz1 * (rsd[i][j][kp1][3] - 2. * rsd[i][j][idx][3] + rsd[i][j][km1][3]);
                frct[i][j][idx][4] = frct[i][j][idx][4] + tz3 * 0.10000000000000001 * 1. * (flux[i][j][kp1][4] - flux[i][j][idx][4]) + dz5 * tz1 * (rsd[i][j][kp1][4] - 2. * rsd[i][j][idx][4] + rsd[i][j][km1][4]);
            }
        }
        for (m = 0; m < 5; m++) {
            frct[i][j][1][m] = frct[i][j][1][m] - dsspm * (+5. * rsd[i][j][1][m] - 4. * rsd[i][j][2][m] + rsd[i][j][3][m]);
            frct[i][j][2][m] = frct[i][j][2][m] - dsspm * (-4. * rsd[i][j][1][m] + 6. * rsd[i][j][2][m] - 4. * rsd[i][j][3][m] + rsd[i][j][4][m]);
        }
        for (k = 3; k <= nz - 4; k += 2) {
            for (int offset = 0; offset < 2 && k + offset <= nz - 4; offset++) {
                int idx = k + offset;
                frct[i][j][idx][0] = frct[i][j][idx][0] - dsspm * (rsd[i][j][idx - 2][0] - 4. * rsd[i][j][idx - 1][0] + 6. * rsd[i][j][idx][0] - 4. * rsd[i][j][idx + 1][0] + rsd[i][j][idx + 2][0]);
                frct[i][j][idx][1] = frct[i][j][idx][1] - dsspm * (rsd[i][j][idx - 2][1] - 4. * rsd[i][j][idx - 1][1] + 6. * rsd[i][j][idx][1] - 4. * rsd[i][j][idx + 1][1] + rsd[i][j][idx + 2][1]);
                frct[i][j][idx][2] = frct[i][j][idx][2] - dsspm * (rsd[i][j][idx - 2][2] - 4. * rsd[i][j][idx - 1][2] + 6. * rsd[i][j][idx][2] - 4. * rsd[i][j][idx + 1][2] + rsd[i][j][idx + 2][2]);
                frct[i][j][idx][3] = frct[i][j][idx][3] - dsspm * (rsd[i][j][idx - 2][3] - 4. * rsd[i][j][idx - 1][3] + 6. * rsd[i][j][idx][3] - 4. * rsd[i][j][idx + 1][3] + rsd[i][j][idx + 2][3]);
                frct[i][j][idx][4] = frct[i][j][idx][4] - dsspm * (rsd[i][j][idx - 2][4] - 4. * rsd[i][j][idx - 1][4] + 6. * rsd[i][j][idx][4] - 4. * rsd[i][j][idx + 1][4] + rsd[i][j][idx + 2][4]);
            }
        }
        for (m = 0; m < 5; m++) {
            frct[i][j][nz - 3][m] = frct[i][j][nz - 3][m] - dsspm * (rsd[i][j][nz - 5][m] - 4. * rsd[i][j][nz - 4][m] + 6. * rsd[i][j][nz - 3][m] - 4. * rsd[i][j][nz - 2][m]);
            frct[i][j][nz - 2][m] = frct[i][j][nz - 2][m] - dsspm * (rsd[i][j][nz - 4][m] - 4. * rsd[i][j][nz - 3][m] + 5. * rsd[i][j][nz - 2][m]);
        }
    }
}
}
