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
        for (k = 0; k < nz; k += 2) {
            double inv_rho, u41_0, u41_1;
            double q0, q1;

            if (k < nz) {
                flux[i][j][k][0] = rsd[i][j][k][3];
                inv_rho = 1.0 / rsd[i][j][k][0];
                u41_0 = rsd[i][j][k][3] * inv_rho;
                q0 = 0.5 * (rsd[i][j][k][1]*rsd[i][j][k][1] + rsd[i][j][k][2]*rsd[i][j][k][2] + rsd[i][j][k][3]*rsd[i][j][k][3]) * inv_rho;
                flux[i][j][k][1] = rsd[i][j][k][1] * u41_0;
                flux[i][j][k][2] = rsd[i][j][k][2] * u41_0;
                flux[i][j][k][3] = rsd[i][j][k][3] * u41_0 + 0.4 * (rsd[i][j][k][4] - q0);
                flux[i][j][k][4] = (1.4 * rsd[i][j][k][4] - 0.4 * q0) * u41_0;
            }

            if (k+1 < nz) {
                flux[i][j][k+1][0] = rsd[i][j][k+1][3];
                inv_rho = 1.0 / rsd[i][j][k+1][0];
                u41_1 = rsd[i][j][k+1][3] * inv_rho;
                q1 = 0.5 * (rsd[i][j][k+1][1]*rsd[i][j][k+1][1] + rsd[i][j][k+1][2]*rsd[i][j][k+1][2] + rsd[i][j][k+1][3]*rsd[i][j][k+1][3]) * inv_rho;
                flux[i][j][k+1][1] = rsd[i][j][k+1][1] * u41_1;
                flux[i][j][k+1][2] = rsd[i][j][k+1][2] * u41_1;
                flux[i][j][k+1][3] = rsd[i][j][k+1][3] * u41_1 + 0.4 * (rsd[i][j][k+1][4] - q1);
                flux[i][j][k+1][4] = (1.4 * rsd[i][j][k+1][4] - 0.4 * q1) * u41_1;
            }
        }

        for (k = 1; k <= nz - 2; k++) {
            double f_diff[5];
            for (m = 0; m < 5; m++) {
                f_diff[m] = flux[i][j][k + 1][m] - flux[i][j][k - 1][m];
            }
            for (m = 0; m < 5; m++) {
                frct[i][j][k][m] -= tz2 * f_diff[m];
            }
        }

        for (k = 1; k < nz; k += 2) {
            if (k < nz) {
                tmp = 1.0 / rsd[i][j][k][0];
                u21k = tmp * rsd[i][j][k][1];
                u31k = tmp * rsd[i][j][k][2];
                u41k = tmp * rsd[i][j][k][3];
                u51k = tmp * rsd[i][j][k][4];
                tmp = 1.0 / rsd[i][j][k-1][0];
                u21km1 = tmp * rsd[i][j][k-1][1];
                u31km1 = tmp * rsd[i][j][k-1][2];
                u41km1 = tmp * rsd[i][j][k-1][3];
                u51km1 = tmp * rsd[i][j][k-1][4];

                flux[i][j][k][1] = tz3 * (u21k - u21km1);
                flux[i][j][k][2] = tz3 * (u31k - u31km1);
                flux[i][j][k][3] = (4.0/3.0) * tz3 * (u41k - u41km1);
                flux[i][j][k][4] = 0.5*(1.0 - 1.96)*tz3*((u21k*u21k + u31k*u31k + u41k*u41k) - (u21km1*u21km1 + u31km1*u31km1 + u41km1*u41km1))
                                 + (1.0/6.0)*tz3*(u41k*u41k - u41km1*u41km1) + 1.96*tz3*(u51k - u51km1);
            }

            if (k+1 < nz) {
                tmp = 1.0 / rsd[i][j][k+1][0];
                u21k = tmp * rsd[i][j][k+1][1];
                u31k = tmp * rsd[i][j][k+1][2];
                u41k = tmp * rsd[i][j][k+1][3];
                u51k = tmp * rsd[i][j][k+1][4];
                tmp = 1.0 / rsd[i][j][k][0];
                u21km1 = tmp * rsd[i][j][k][1];
                u31km1 = tmp * rsd[i][j][k][2];
                u41km1 = tmp * rsd[i][j][k][3];
                u51km1 = tmp * rsd[i][j][k][4];

                flux[i][j][k+1][1] = tz3 * (u21k - u21km1);
                flux[i][j][k+1][2] = tz3 * (u31k - u31km1);
                flux[i][j][k+1][3] = (4.0/3.0) * tz3 * (u41k - u41km1);
                flux[i][j][k+1][4] = 0.5*(1.0 - 1.96)*tz3*((u21k*u21k + u31k*u31k + u41k*u41k) - (u21km1*u21km1 + u31km1*u31km1 + u41km1*u41km1))
                                   + (1.0/6.0)*tz3*(u41k*u41k - u41km1*u41km1) + 1.96*tz3*(u51k - u51km1);
            }
        }

        for (k = 1; k <= nz - 2; k++) {
            double lap0 = rsd[i][j][k+1][0] - 2.0*rsd[i][j][k][0] + rsd[i][j][k-1][0];
            double lap1 = rsd[i][j][k+1][1] - 2.0*rsd[i][j][k][1] + rsd[i][j][k-1][1];
            double lap2 = rsd[i][j][k+1][2] - 2.0*rsd[i][j][k][2] + rsd[i][j][k-1][2];
            double lap3 = rsd[i][j][k+1][3] - 2.0*rsd[i][j][k][3] + rsd[i][j][k-1][3];
            double lap4 = rsd[i][j][k+1][4] - 2.0*rsd[i][j][k][4] + rsd[i][j][k-1][4];

            frct[i][j][k][0] += dz1 * tz1 * lap0;
            frct[i][j][k][1] += tz3 * 0.1 * (flux[i][j][k+1][1] - flux[i][j][k][1]) + dz2 * tz1 * lap1;
            frct[i][j][k][2] += tz3 * 0.1 * (flux[i][j][k+1][2] - flux[i][j][k][2]) + dz3 * tz1 * lap2;
            frct[i][j][k][3] += tz3 * 0.1 * (flux[i][j][k+1][3] - flux[i][j][k][3]) + dz4 * tz1 * lap3;
            frct[i][j][k][4] += tz3 * 0.1 * (flux[i][j][k+1][4] - flux[i][j][k][4]) + dz5 * tz1 * lap4;
        }

        for (m = 0; m < 5; m++) {
            frct[i][j][1][m] -= dsspm * (+5.0 * rsd[i][j][1][m] - 4.0 * rsd[i][j][2][m] + rsd[i][j][3][m]);
            frct[i][j][2][m] -= dsspm * (-4.0 * rsd[i][j][1][m] + 6.0 * rsd[i][j][2][m] - 4.0 * rsd[i][j][3][m] + rsd[i][j][4][m]);
        }

        for (k = 3; k <= nz - 4; k++) {
            double stencil_sum[5];
            for (m = 0; m < 5; m++) {
                stencil_sum[m] = rsd[i][j][k-2][m] - 4.0*rsd[i][j][k-1][m] + 6.0*rsd[i][j][k][m] - 4.0*rsd[i][j][k+1][m] + rsd[i][j][k+2][m];
                frct[i][j][k][m] -= dsspm * stencil_sum[m];
            }
        }

        for (m = 0; m < 5; m++) {
            frct[i][j][nz-3][m] -= dsspm * (rsd[i][j][nz-5][m] - 4.0*rsd[i][j][nz-4][m] + 6.0*rsd[i][j][nz-3][m] - 4.0*rsd[i][j][nz-2][m]);
            frct[i][j][nz-2][m] -= dsspm * (rsd[i][j][nz-4][m] - 4.0*rsd[i][j][nz-3][m] + 5.0*rsd[i][j][nz-2][m]);
        }
    }
}
}
