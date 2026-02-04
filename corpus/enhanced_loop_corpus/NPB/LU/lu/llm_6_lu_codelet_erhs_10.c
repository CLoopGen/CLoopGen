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
        for (k = 0; k <= nz - 1; k++) {
            double tmp_rsd_ik = rsd[i][j][k][0];
            flux[i][j][k][0] = rsd[i][j][k][3];
            u41 = rsd[i][j][k][3] / tmp_rsd_ik;
            q = 0.5 * (rsd[i][j][k][1] * rsd[i][j][k][1] + rsd[i][j][k][2] * rsd[i][j][k][2] + rsd[i][j][k][3] * rsd[i][j][k][3]) / tmp_rsd_ik;
            flux[i][j][k][1] = rsd[i][j][k][1] * u41;
            flux[i][j][k][2] = rsd[i][j][k][2] * u41;
            flux[i][j][k][3] = rsd[i][j][k][3] * u41 + 0.4 * (rsd[i][j][k][4] - q);
            flux[i][j][k][4] = (1.4 * rsd[i][j][k][4] - 0.4 * q) * u41;
        }
        for (k = 1; k <= nz - 2; k++) {
            for (m = 0; m < 5; m++) {
                double prev_flux = flux[i][j][k - 1][m];
                double curr_flux = flux[i][j][k][m];
                double next_flux = flux[i][j][k + 1][m];
                double diff = tz2 * (next_flux - prev_flux);
                frct[i][j][k][m] -= diff;
            }
        }
        for (k = 1; k <= nz - 1; k++) {
            double tmp_curr = 1.0 / rsd[i][j][k][0];
            double tmp_prev = 1.0 / rsd[i][j][k - 1][0];
            u21k = tmp_curr * rsd[i][j][k][1];
            u31k = tmp_curr * rsd[i][j][k][2];
            u41k = tmp_curr * rsd[i][j][k][3];
            u51k = tmp_curr * rsd[i][j][k][4];
            u21km1 = tmp_prev * rsd[i][j][k - 1][1];
            u31km1 = tmp_prev * rsd[i][j][k - 1][2];
            u41km1 = tmp_prev * rsd[i][j][k - 1][3];
            u51km1 = tmp_prev * rsd[i][j][k - 1][4];
            flux[i][j][k][1] = tz3 * (u21k - u21km1);
            flux[i][j][k][2] = tz3 * (u31k - u31km1);
            flux[i][j][k][3] = (4.0/3.0) * tz3 * (u41k - u41km1);
            double vel_diff_k = (u21k*u21k + u31k*u31k + u41k*u41k);
            double vel_diff_km1 = (u21km1*u21km1 + u31km1*u31km1 + u41km1*u41km1);
            flux[i][j][k][4] = 0.5 * (1. - 1.96) * tz3 * (vel_diff_k - vel_diff_km1)
                             + (1./6.) * tz3 * (u41k*u41k - u41km1*u41km1)
                             + 1.96 * tz3 * (u51k - u51km1);
        }
        for (k = 1; k <= nz - 2; k++) {
            frct[i][j][k][0] += dz1 * tz1 * (rsd[i][j][k+1][0] - 2.*rsd[i][j][k][0] + rsd[i][j][k-1][0]);
            frct[i][j][k][1] += tz3 * 0.1 * (flux[i][j][k+1][1] - flux[i][j][k][1]) + dz2 * tz1 * (rsd[i][j][k+1][1] - 2.*rsd[i][j][k][1] + rsd[i][j][k-1][1]);
            frct[i][j][k][2] += tz3 * 0.1 * (flux[i][j][k+1][2] - flux[i][j][k][2]) + dz3 * tz1 * (rsd[i][j][k+1][2] - 2.*rsd[i][j][k][2] + rsd[i][j][k-1][2]);
            frct[i][j][k][3] += tz3 * 0.1 * (flux[i][j][k+1][3] - flux[i][j][k][3]) + dz4 * tz1 * (rsd[i][j][k+1][3] - 2.*rsd[i][j][k][3] + rsd[i][j][k-1][3]);
            frct[i][j][k][4] += tz3 * 0.1 * (flux[i][j][k+1][4] - flux[i][j][k][4]) + dz5 * tz1 * (rsd[i][j][k+1][4] - 2.*rsd[i][j][k][4] + rsd[i][j][k-1][4]);
        }
        for (m = 0; m < 5; m++) {
            frct[i][j][1][m] -= dsspm * (+5. * rsd[i][j][1][m] - 4. * rsd[i][j][2][m] + rsd[i][j][3][m]);
            frct[i][j][2][m] -= dsspm * (-4. * rsd[i][j][1][m] + 6. * rsd[i][j][2][m] - 4. * rsd[i][j][3][m] + rsd[i][j][4][m]);
        }
        for (k = 3; k <= nz - 4; k++) {
            for (m = 0; m < 5; m++) {
                frct[i][j][k][m] -= dsspm * (rsd[i][j][k-2][m] - 4.*rsd[i][j][k-1][m] + 6.*rsd[i][j][k][m] - 4.*rsd[i][j][k+1][m] + rsd[i][j][k+2][m]);
            }
        }
        for (m = 0; m < 5; m++) {
            frct[i][j][nz-3][m] -= dsspm * (rsd[i][j][nz-5][m] - 4.*rsd[i][j][nz-4][m] + 6.*rsd[i][j][nz-3][m] - 4.*rsd[i][j][nz-2][m]);
            frct[i][j][nz-2][m] -= dsspm * (rsd[i][j][nz-4][m] - 4.*rsd[i][j][nz-3][m] + 5.*rsd[i][j][nz-2][m]);
        }
    }
}
}
