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
        // Introduce layered control: split logic into phases based on nz thresholds
        const int phase1_end = (nz > 5) ? 2 : nz - 1;
        const int phase2_start = (nz > 5) ? 3 : 1;
        const int phase2_end = (nz > 5) ? nz - 4 : nz - 2;

        // Phase 0: Compute base flux values
        for (k = 0; k < nz; k++) {
            double rho_inv = 1.0 / rsd[i][j][k][0];
            u41 = rsd[i][j][k][3] * rho_inv;
            double u1_sq = rsd[i][j][k][1] * rsd[i][j][k][1] +
                           rsd[i][j][k][2] * rsd[i][j][k][2] +
                           rsd[i][j][k][3] * rsd[i][j][k][3];
            q = 0.5 * u1_sq * rho_inv;

            flux[i][j][k][0] = rsd[i][j][k][3];
            flux[i][j][k][1] = rsd[i][j][k][1] * u41;
            flux[i][j][k][2] = rsd[i][j][k][2] * u41;
            flux[i][j][k][3] = rsd[i][j][k][3] * u41 + 0.4 * (rsd[i][j][k][4] - q);
            flux[i][j][k][4] = (1.4 * rsd[i][j][k][4] - 0.4 * q) * u41;
        }

        // Phase 1: Central difference update (limited to safe interior)
        if (nz >= 3) {
            for (k = 1; k <= nz - 2; k++) {
                for (m = 0; m < 5; m++) {
                    frct[i][j][k][m] = frct[i][j][k][m] - tz2 * (flux[i][j][k+1][m] - flux[i][j][k-1][m]);
                }
            }
        }

        // Phase 2: Velocity gradient-based flux update
        for (k = 1; k < nz; k++) {
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

            double vdiff_sq = (u21k*u21k + u31k*u31k + u41k*u41k) - (u21km1*u21km1 + u31km1*u31km1 + u41km1*u41km1);
            double u4_diff_sq = u41k*u41k - u41km1*u41km1;
            double gamma = 1.4;
            flux[i][j][k][4] = 0.5*(1. - gamma*gamma)*tz3*vdiff_sq
                             + (1./6.)*tz3*u4_diff_sq
                             + gamma*gamma*tz3*(u51k - u51km1);
        }

        // Phase 3a: Diffusion and correction terms in central zone
        for (k = 1; k <= nz - 2; k++) {
            frct[i][j][k][0] += dz1 * tz1 * (rsd[i][j][k+1][0] - 2.*rsd[i][j][k][0] + rsd[i][j][k-1][0]);

            // Conditional application per field component using compact logic
            for (m = 1; m < 5; m++) {
                double flux_diff = flux[i][j][k+1][m] - flux[i][j][k][m];
                double rsd_laplace = rsd[i][j][k+1][m] - 2.*rsd[i][j][k][m] + rsd[i][j][k-1][m];
                double dz_coeff = (m == 1) ? dz2 : (m == 2) ? dz3 : (m == 3) ? dz4 : dz5;
                frct[i][j][k][m] += tz3 * 0.1 * flux_diff + dz_coeff * tz1 * rsd_laplace;
            }
        }

        // Phase 3b: Boundary damping with adaptive path selection
        if (nz > 4) {
            // Full stencil near boundaries
            for (m = 0; m < 5; m++) {
                frct[i][j][1][m] -= dsspm * ( 5.*rsd[i][j][1][m] - 4.*rsd[i][j][2][m] + rsd[i][j][3][m]);
                frct[i][j][2][m] -= dsspm * (-4.*rsd[i][j][1][m] + 6.*rsd[i][j][2][m] - 4.*rsd[i][j][3][m] + rsd[i][j][4][m]);
            }
            for (k = phase2_start; k <= phase2_end; k++) {
                for (m = 0; m < 5; m++) {
                    frct[i][j][k][m] -= dsspm * (rsd[i][j][k-2][m] - 4.*rsd[i][j][k-1][m] + 6.*rsd[i][j][k][m] - 4.*rsd[i][j][k+1][m] + rsd[i][j][k+2][m]);
                }
            }
            for (m = 0; m < 5; m++) {
                frct[i][j][nz-3][m] -= dsspm * (rsd[i][j][nz-5][m] - 4.*rsd[i][j][nz-4][m] + 6.*rsd[i][j][nz-3][m] - 4.*rsd[i][j][nz-2][m]);
                frct[i][j][nz-2][m] -= dsspm * (rsd[i][j][nz-4][m] - 4.*rsd[i][j][nz-3][m] + 5.*rsd[i][j][nz-2][m]);
            }
        } else {
            // Reduced damping for thin domains
            for (k = 1; k <= nz - 2; k++) {
                for (m = 0; m < 5; m++) {
                    if (k == 1) {
                        frct[i][j][k][m] -= dsspm * (2.*rsd[i][j][k][m] - 2.*rsd[i][j][k+1][m]);
                    } else if (k == nz - 2) {
                        frct[i][j][k][m] -= dsspm * (2.*rsd[i][j][k][m] - 2.*rsd[i][j][k-1][m]);
                    } else {
                        frct[i][j][k][m] -= dsspm * (rsd[i][j][k-1][m] - 2.*rsd[i][j][k][m] + rsd[i][j][k+1][m]);
                    }
                }
            }
        }
    }
}
}
