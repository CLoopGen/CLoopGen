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
        // Combined computation of convective flux and immediate residual update where possible
        for (k = 0; k < nz; k++) {
            double inv_u0 = 1.0 / u[i][j][k][0];
            u41 = u[i][j][k][3] * inv_u0;
            q = 0.5 * (u[i][j][k][1]*u[i][j][k][1] + 
                      u[i][j][k][2]*u[i][j][k][2] + 
                      u[i][j][k][3]*u[i][j][k][3]) * inv_u0;

            flux[i][j][k][0] = u[i][j][k][3];
            flux[i][j][k][1] = u[i][j][k][1] * u41;
            flux[i][j][k][2] = u[i][j][k][2] * u41;
            flux[i][j][k][3] = u[i][j][k][3] * u41 + 0.4 * (u[i][j][k][4] - q);
            flux[i][j][k][4] = (1.4 * u[i][j][k][4] - 0.4 * q) * u41;
        }

        // Overlap residual updates: handle both convection and diffusion in one sweep for k ∈ [1, nz-2]
        for (k = 1; k <= nz - 2; k++) {
            // Update residual from convection (central difference)
            for (m = 0; m < 5; m++) {
                rsd[i][j][k][m] -= tz2 * (flux[i][j][k+1][m] - flux[i][j][k-1][m]);
            }

            // Compute viscous flux from normalized variables
            double tmp_k   = 1.0 / u[i][j][k][0];
            double tmp_km1 = 1.0 / u[i][j][k-1][0];
            double tmp_kp1 = 1.0 / u[i][j][k+1][0];  // needed for symmetric stencil

            double u21k = tmp_k * u[i][j][k][1],   u21km1 = tmp_km1 * u[i][j][k-1][1];
            double u31k = tmp_k * u[i][j][k][2],   u31km1 = tmp_km1 * u[i][j][k-1][2];
            double u41k = tmp_k * u[i][j][k][3],   u41km1 = tmp_km1 * u[i][j][k-1][3];
            double u51k = tmp_k * u[i][j][k][4],   u51km1 = tmp_km1 * u[i][j][k-1][4];

            double u21kp1 = tmp_kp1 * u[i][j][k+1][1];
            double u31kp1 = tmp_kp1 * u[i][j][k+1][2];
            double u41kp1 = tmp_kp1 * u[i][j][k+1][3];
            double u51kp1 = tmp_kp1 * u[i][j][k+1][4];

            flux[i][j][k][1] = tz3 * (u21k - u21km1);
            flux[i][j][k+1][1] = tz3 * (u21kp1 - u21k);  // precompute next

            flux[i][j][k][2] = tz3 * (u31k - u31km1);
            flux[i][j][k+1][2] = tz3 * (u31kp1 - u31k);

            flux[i][j][k][3] = (4.0/3.0) * tz3 * (u41k - u41km1);
            flux[i][j][k+1][3] = (4.0/3.0) * tz3 * (u41kp1 - u41k);

            double sq_k   = u21k*u21k + u31k*u31k + u41k*u41k;
            double sq_km1 = u21km1*u21km1 + u31km1*u31km1 + u41km1*u41km1;
            double sq_kp1 = u21kp1*u21kp1 + u31kp1*u31kp1 + u41kp1*u41kp1;

            flux[i][j][k][4] = 0.5*(1.0 - 1.96)*tz3*(sq_k - sq_km1) +
                              (1.0/6.0)*tz3*((u41k*u41k) - (u41km1*u41km1)) +
                              1.96*tz3*(u51k - u51km1);

            flux[i][j][k+1][4] = 0.5*(1.0 - 1.96)*tz3*(sq_kp1 - sq_k) +
                                (1.0/6.0)*tz3*((u41kp1*u41kp1) - (u41k*u41k)) +
                                1.96*tz3*(u51kp1 - u51k);

            // Add diffusion and artificial dissipation contributions
            double um1, u0, up1;
            um1 = u[i][j][k-1][0]; u0 = u[i][j][k][0]; up1 = u[i][j][k+1][0];
            rsd[i][j][k][0] += dz1 * tz1 * (um1 - 2.0*u0 + up1);

            um1 = u[i][j][k-1][1]; u0 = u[i][j][k][1]; up1 = u[i][j][k+1][1];
            rsd[i][j][k][1] += tz3 * 0.1 * (flux[i][j][k+1][1] - flux[i][j][k][1]) + 
                               dz2 * tz1 * (um1 - 2.0*u0 + up1);

            um1 = u[i][j][k-1][2]; u0 = u[i][j][k][2]; up1 = u[i][j][k+1][2];
            rsd[i][j][k][2] += tz3 * 0.1 * (flux[i][j][k+1][2] - flux[i][j][k][2]) + 
                               dz3 * tz1 * (um1 - 2.0*u0 + up1);

            um1 = u[i][j][k-1][3]; u0 = u[i][j][k][3]; up1 = u[i][j][k+1][3];
            rsd[i][j][k][3] += tz3 * 0.1 * (flux[i][j][k+1][3] - flux[i][j][k][3]) + 
                               dz4 * tz1 * (um1 - 2.0*u0 + up1);

            um1 = u[i][j][k-1][4]; u0 = u[i][j][k][4]; up1 = u[i][j][k+1][4];
            rsd[i][j][k][4] += tz3 * 0.1 * (flux[i][j][k+1][4] - flux[i][j][k][4]) + 
                               dz5 * tz1 * (um1 - 2.0*u0 + up1);
        }

        // Boundary treatment with early exits via control flow simplification
        if (nz <= 5) {
            for (m = 0; m < 5; m++) {
                if (nz >= 4) {
                    rsd[i][j][1][m] -= dssp * (5.0 * u[i][j][1][m] - 4.0 * u[i][j][2][m] + u[i][j][3][m]);
                }
                if (nz >= 5) {
                    rsd[i][j][2][m] -= dssp * (-4.0 * u[i][j][1][m] + 6.0 * u[i][j][2][m] - 4.0 * u[i][j][3][m] + u[i][j][4][m]);
                }
            }
            continue;  // Skip full stencil application
        }

        // Apply full 5-point stencil in the core region
        for (m = 0; m < 5; m++) {
            rsd[i][j][1][m] -= dssp * (5.0 * u[i][j][1][m] - 4.0 * u[i][j][2][m] + u[i][j][3][m]);
            rsd[i][j][2][m] -= dssp * (-4.0 * u[i][j][1][m] + 6.0 * u[i][j][2][m] - 4.0 * u[i][j][3][m] + u[i][j][4][m]);
        }

        for (k = 3; k <= nz - 4; k++) {
            for (m = 0; m < 5; m++) {
                rsd[i][j][k][m] -= dssp * (u[i][j][k-2][m] - 4.0*u[i][j][k-1][m] + 
                                          6.0*u[i][j][k][m] - 4.0*u[i][j][k+1][m] + 
                                          u[i][j][k+2][m]);
            }
        }

        for (m = 0; m < 5; m++) {
            rsd[i][j][nz-3][m] -= dssp * (u[i][j][nz-5][m] - 4.0*u[i][j][nz-4][m] + 
                                         6.0*u[i][j][nz-3][m] - 4.0*u[i][j][nz-2][m]);
            rsd[i][j][nz-2][m] -= dssp * (u[i][j][nz-4][m] - 4.0*u[i][j][nz-3][m] + 
                                         5.0*u[i][j][nz-2][m]);
        }
    }
}
}
