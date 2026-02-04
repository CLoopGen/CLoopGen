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
            double inv_rho = 1.0 / u[i][j][k][0];
            double u41 = u[i][j][k][3] * inv_rho;
            double q = 0.5 * (u[i][j][k][1]*u[i][j][k][1] + u[i][j][k][2]*u[i][j][k][2] + u[i][j][k][3]*u[i][j][k][3]) * inv_rho;
            flux[i][j][k][0] = u[i][j][k][3];
            flux[i][j][k][1] = u[i][j][k][1] * u41;
            flux[i][j][k][2] = u[i][j][k][2] * u41;
            flux[i][j][k][3] = u[i][j][k][3] * u41 + 0.4 * (u[i][j][k][4] - q);
            flux[i][j][k][4] = (1.4 * u[i][j][k][4] - 0.4 * q) * u41;
        }
        for (k = 1; k <= nz - 2; k++) {
            double flux_diff[5];
            for (m = 0; m < 5; m++) {
                flux_diff[m] = tz2 * (flux[i][j][k + 1][m] - flux[i][j][k - 1][m]);
            }
            for (m = 0; m < 5; m++) {
                rsd[i][j][k][m] -= flux_diff[m];
            }
        }
        for (k = 1; k <= nz - 1; k++) {
            double rho_k = u[i][j][k][0], rho_km1 = u[i][j][k-1][0];
            double u21k = u[i][j][k][1] / rho_k;
            double u31k = u[i][j][k][2] / rho_k;
            double u41k = u[i][j][k][3] / rho_k;
            double u51k = u[i][j][k][4] / rho_k;
            double u21km1 = u[i][j][k-1][1] / rho_km1;
            double u31km1 = u[i][j][k-1][2] / rho_km1;
            double u41km1 = u[i][j][k-1][3] / rho_km1;
            double u51km1 = u[i][j][k-1][4] / rho_km1;
            flux[i][j][k][1] = tz3 * (u21k - u21km1);
            flux[i][j][k][2] = tz3 * (u31k - u31km1);
            flux[i][j][k][3] = (4.0/3.0) * tz3 * (u41k - u41km1);
            double term1 = (((u21k)*(u21k)) + ((u31k)*(u31k)) + ((u41k)*(u41k))) - (((u21km1)*(u21km1)) + ((u31km1)*(u31km1)) + ((u41km1)*(u41km1)));
            double term2 = ((u41k)*(u41k)) - ((u41km1)*(u41km1));
            double term3 = u51k - u51km1;
            flux[i][j][k][4] = 0.5*(1.0 - 1.96)*tz3*term1 + (1.0/6.0)*tz3*term2 + 1.96*tz3*term3;
        }
        for (k = 1; k <= nz - 2; k++) {
            double laplacian[5];
            for (m = 0; m < 5; m++) {
                laplacian[m] = u[i][j][k-1][m] - 2.0*u[i][j][k][m] + u[i][j][k+1][m];
            }
            double flux_contrib[5];
            for (m = 1; m < 5; m++) {
                flux_contrib[m] = tz3 * 0.1 * (flux[i][j][k+1][m] - flux[i][j][k][m]);
            }
            rsd[i][j][k][0] += dz1 * tz1 * laplacian[0];
            for (m = 1; m < 5; m++) {
                double coeff = (m == 1) ? dz2 : (m == 2) ? dz3 : (m == 3) ? dz4 : dz5;
                rsd[i][j][k][m] += flux_contrib[m] + coeff * tz1 * laplacian[m];
            }
        }
        double dssp_factor = dssp;
        for (m = 0; m < 5; m++) {
            rsd[i][j][1][m] -= dssp_factor * (+5.0 * u[i][j][1][m] - 4.0 * u[i][j][2][m] + u[i][j][3][m]);
            rsd[i][j][2][m] -= dssp_factor * (-4.0 * u[i][j][1][m] + 6.0 * u[i][j][2][m] - 4.0 * u[i][j][3][m] + u[i][j][4][m]);
        }
        for (k = 3; k <= nz - 4; k++) {
            double stencil_sum[5] = {0};
            for (m = 0; m < 5; m++) {
                stencil_sum[m] = u[i][j][k-2][m] - 4.0*u[i][j][k-1][m] + 6.0*u[i][j][k][m] - 4.0*u[i][j][k+1][m] + u[i][j][k+2][m];
                rsd[i][j][k][m] -= dssp_factor * stencil_sum[m];
            }
        }
        for (m = 0; m < 5; m++) {
            rsd[i][j][nz-3][m] -= dssp_factor * (u[i][j][nz-5][m] - 4.0*u[i][j][nz-4][m] + 6.0*u[i][j][nz-3][m] - 4.0*u[i][j][nz-2][m]);
            rsd[i][j][nz-2][m] -= dssp_factor * (u[i][j][nz-4][m] - 4.0*u[i][j][nz-3][m] + 5.0*u[i][j][nz-2][m]);
        }
    }
}
}
