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
extern  double dssp;
extern  double u[64][65][65][5];
extern  double rsd[64][65][65][5];
extern  double flux[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;
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
            double u41_local = u[i][j][k][3] / u[i][j][k][0];
            double q_local = 0.5 * (u[i][j][k][1] * u[i][j][k][1] + u[i][j][k][2] * u[i][j][k][2] + u[i][j][k][3] * u[i][j][k][3]) / u[i][j][k][0];
            flux[i][j][k][0] = u[i][j][k][3];
            flux[i][j][k][1] = u[i][j][k][1] * u41_local;
            flux[i][j][k][2] = u[i][j][k][2] * u41_local;
            flux[i][j][k][3] = u[i][j][k][3] * u41_local + 0.4 * (u[i][j][k][4] - q_local);
            flux[i][j][k][4] = (1.4 * u[i][j][k][4] - 0.4 * q_local) * u41_local;
        }
        for (k = 1; k <= nz - 2; k++) {
            for (m = 0; m < 5; m++) {
                double diff_flux = tz2 * (flux[i][j][k + 1][m] - flux[i][j][k - 1][m]);
                rsd[i][j][k][m] -= diff_flux;
            }
        }
        for (k = 1; k <= nz - 1; k++) {
            double tmp_k = 1.0 / u[i][j][k][0];
            double tmp_km1 = 1.0 / u[i][j][k - 1][0];
            double u21k = tmp_k * u[i][j][k][1];
            double u31k = tmp_k * u[i][j][k][2];
            double u41k = tmp_k * u[i][j][k][3];
            double u51k = tmp_k * u[i][j][k][4];
            double u21km1 = tmp_km1 * u[i][j][k - 1][1];
            double u31km1 = tmp_km1 * u[i][j][k - 1][2];
            double u41km1 = tmp_km1 * u[i][j][k - 1][3];
            double u51km1 = tmp_km1 * u[i][j][k - 1][4];
            flux[i][j][k][1] = tz3 * (u21k - u21km1);
            flux[i][j][k][2] = tz3 * (u31k - u31km1);
            flux[i][j][k][3] = (4.0/3.0) * tz3 * (u41k - u41km1);
            double vel_diff_sq = ((u21k*u21k + u31k*u31k + u41k*u41k) - (u21km1*u21km1 + u31km1*u31km1 + u41km1*u41km1));
            double u4_sq_diff = (u41k*u41k - u41km1*u41km1);
            double u5_diff = u51k - u51km1;
            flux[i][j][k][4] = 0.5*(1.0 - 1.96)*tz3*vel_diff_sq + (1.0/6.0)*tz3*u4_sq_diff + 1.96*tz3*u5_diff;
        }
        for (k = 1; k <= nz - 2; k++) {
            double um1_0 = u[i][j][k - 1][0], u0_0 = u[i][j][k][0], up1_0 = u[i][j][k + 1][0];
            rsd[i][j][k][0] += dz1 * tz1 * (um1_0 - 2.0*u0_0 + up1_0);
            for (m = 1; m <= 4; m++) {
                double coeff = (m == 1) ? dz2 : (m == 2) ? dz3 : (m == 3) ? dz4 : dz5;
                double um1 = u[i][j][k - 1][m];
                double u0 = u[i][j][k][m];
                double up1 = u[i][j][k + 1][m];
                double laplacian_u = um1 - 2.0*u0 + up1;
                double flux_diff = tz3 * 0.1 * (flux[i][j][k + 1][m] - flux[i][j][k][m]);
                rsd[i][j][k][m] += flux_diff + coeff * tz1 * laplacian_u;
            }
        }
        for (m = 0; m < 5; m++) {
            rsd[i][j][1][m] -= dssp * (+5.0 * u[i][j][1][m] - 4.0 * u[i][j][2][m] + u[i][j][3][m]);
            rsd[i][j][2][m] -= dssp * (-4.0 * u[i][j][1][m] + 6.0 * u[i][j][2][m] - 4.0 * u[i][j][3][m] + u[i][j][4][m]);
        }
        for (k = 3; k <= nz - 4; k++) {
            for (m = 0; m < 5; m++) {
                rsd[i][j][k][m] -= dssp * (u[i][j][k-2][m] - 4.0*u[i][j][k-1][m] + 6.0*u[i][j][k][m] - 4.0*u[i][j][k+1][m] + u[i][j][k+2][m]);
            }
        }
        for (m = 0; m < 5; m++) {
            rsd[i][j][nz-3][m] -= dssp * (u[i][j][nz-5][m] - 4.0*u[i][j][nz-4][m] + 6.0*u[i][j][nz-3][m] - 4.0*u[i][j][nz-2][m]);
            rsd[i][j][nz-2][m] -= dssp * (u[i][j][nz-4][m] - 4.0*u[i][j][nz-3][m] + 5.0*u[i][j][nz-2][m]);
        }
    }
}
}
