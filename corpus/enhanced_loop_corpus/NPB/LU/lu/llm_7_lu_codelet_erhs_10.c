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
            double r0 = rsd[i][j][k][0];
            double r1 = rsd[i][j][k][1];
            double r2 = rsd[i][j][k][2];
            double r3 = rsd[i][j][k][3];
            double r4 = rsd[i][j][k][4];
            flux[i][j][k][0] = r3;
            double inv_r0 = 1.0 / r0;
            u41 = r3 * inv_r0;
            q = 0.5 * (r1*r1 + r2*r2 + r3*r3) * inv_r0;
            flux[i][j][k][1] = r1 * u41;
            flux[i][j][k][2] = r2 * u41;
            flux[i][j][k][3] = r3 * u41 + 0.4 * (r4 - q);
            flux[i][j][k][4] = (1.4 * r4 - 0.4 * q) * u41;
        }
        for (k = 1; k <= nz - 2; k++) {
            double temp_flux[5];
            for (m = 0; m < 5; m++) {
                temp_flux[m] = tz2 * (flux[i][j][k+1][m] - flux[i][j][k-1][m]);
            }
            for (m = 0; m < 5; m++) {
                frct[i][j][k][m] -= temp_flux[m];
            }
        }
        for (k = 1; k <= nz - 1; k++) {
            double r0_curr = rsd[i][j][k][0];
            double r1_curr = rsd[i][j][k][1];
            double r2_curr = rsd[i][j][k][2];
            double r3_curr = rsd[i][j][k][3];
            double r4_curr = rsd[i][j][k][4];
            double r0_prev = rsd[i][j][k-1][0];
            double r1_prev = rsd[i][j][k-1][1];
            double r2_prev = rsd[i][j][k-1][2];
            double r3_prev = rsd[i][j][k-1][3];
            double r4_prev = rsd[i][j][k-1][4];
            double inv_curr = 1.0 / r0_curr;
            double inv_prev = 1.0 / r0_prev;
            u21k = r1_curr * inv_curr;
            u31k = r2_curr * inv_curr;
            u41k = r3_curr * inv_curr;
            u51k = r4_curr * inv_curr;
            u21km1 = r1_prev * inv_prev;
            u31km1 = r2_prev * inv_prev;
            u41km1 = r3_prev * inv_prev;
            u51km1 = r4_prev * inv_prev;
            flux[i][j][k][1] = tz3 * (u21k - u21km1);
            flux[i][j][k][2] = tz3 * (u31k - u31km1);
            flux[i][j][k][3] = (4.0/3.0) * tz3 * (u41k - u41km1);
            double v2_curr = u21k*u21k + u31k*u31k + u41k*u41k;
            double v2_prev = u21km1*u21km1 + u31km1*u31km1 + u41km1*u41km1;
            flux[i][j][k][4] = tz3 * (0.5*(1.0 - 1.96)*(v2_curr - v2_prev) 
                             + (1.0/6.0)*(u41k*u41k - u41km1*u41km1) 
                             + 1.96*(u51k - u51km1));
        }
        for (k = 1; k <= nz - 2; k++) {
            double rsd_im2[5], rsd_im1[5], rsd_ip1[5], rsd_ip2[5];
            for (m = 0; m < 5; m++) {
                rsd_im2[m] = rsd[i][j][k-2][m];
                rsd_im1[m] = rsd[i][j][k-1][m];
                rsd_ip1[m] = rsd[i][j][k+1][m];
                rsd_ip2[m] = rsd[i][j][k+2][m];
            }
            frct[i][j][k][0] += dz1 * tz1 * (rsd_ip1[0] - 2.*rsd[i][j][k][0] + rsd_im1[0]);
            frct[i][j][k][1] += tz3 * 0.1 * (flux[i][j][k+1][1] - flux[i][j][k][1]) + dz2 * tz1 * (rsd_ip1[1] - 2.*rsd[i][j][k][1] + rsd_im1[1]);
            frct[i][j][k][2] += tz3 * 0.1 * (flux[i][j][k+1][2] - flux[i][j][k][2]) + dz3 * tz1 * (rsd_ip1[2] - 2.*rsd[i][j][k][2] + rsd_im1[2]);
            frct[i][j][k][3] += tz3 * 0.1 * (flux[i][j][k+1][3] - flux[i][j][k][3]) + dz4 * tz1 * (rsd_ip1[3] - 2.*rsd[i][j][k][3] + rsd_im1[3]);
            frct[i][j][k][4] += tz3 * 0.1 * (flux[i][j][k+1][4] - flux[i][j][k][4]) + dz5 * tz1 * (rsd_ip1[4] - 2.*rsd[i][j][k][4] + rsd_im1[4]);
            if (k >= 3 && k <= nz - 4) {
                for (m = 0; m < 5; m++) {
                    frct[i][j][k][m] -= dsspm * (rsd_im2[m] - 4.*rsd_im1[m] + 6.*rsd[i][j][k][m] - 4.*rsd_ip1[m] + rsd_ip2[m]);
                }
            }
        }
        for (m = 0; m < 5; m++) {
            frct[i][j][1][m] -= dsspm * (+5. * rsd[i][j][1][m] - 4. * rsd[i][j][2][m] + rsd[i][j][3][m]);
            frct[i][j][2][m] -= dsspm * (-4. * rsd[i][j][1][m] + 6. * rsd[i][j][2][m] - 4. * rsd[i][j][3][m] + rsd[i][j][4][m]);
            if (nz >= 5) {
                frct[i][j][nz-3][m] -= dsspm * (rsd[i][j][nz-5][m] - 4.*rsd[i][j][nz-4][m] + 6.*rsd[i][j][nz-3][m] - 4.*rsd[i][j][nz-2][m]);
                frct[i][j][nz-2][m] -= dsspm * (rsd[i][j][nz-4][m] - 4.*rsd[i][j][nz-3][m] + 5.*rsd[i][j][nz-2][m]);
            }
        }
    }
}
}
