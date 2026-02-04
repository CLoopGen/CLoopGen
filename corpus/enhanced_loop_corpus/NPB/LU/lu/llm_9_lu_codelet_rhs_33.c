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
        for (k = 0; k < nz; k++) {
            double inv_rho = 1.0 / u[i][j][k][0];
            double u1 = u[i][j][k][1], u2 = u[i][j][k][2], u3 = u[i][j][k][3], e = u[i][j][k][4];
            double q_sq = 0.5 * (u1*u1 + u2*u2 + u3*u3) * inv_rho;
            double u41 = u3 * inv_rho;
            flux[i][j][k][0] = u3;
            flux[i][j][k][1] = u1 * u41;
            flux[i][j][k][2] = u2 * u41;
            flux[i][j][k][3] = u3 * u41 + 0.4 * (e - q_sq);
            flux[i][j][k][4] = (1.4 * e - 0.4 * q_sq) * u41;
        }
        for (k = 2; k <= nz - 3; k += 2) {
            for (m = 0; m < 5; m++) {
                double forward = flux[i][j][k+1][m] - flux[i][j][k-1][m];
                double backward = flux[i][j][k][m] - flux[i][j][k-2][m];
                rsd[i][j][k][m] -= tz2 * forward;
                rsd[i][j][k-1][m] -= tz2 * backward;
            }
        }
        for (k = 2; k < nz; k++) {
            double tmp_curr = 1.0 / u[i][j][k][0];
            double tmp_prev = 1.0 / u[i][j][k-1][0];
            double vars_k[4] = {
                tmp_curr * u[i][j][k][1],
                tmp_curr * u[i][j][k][2],
                tmp_curr * u[i][j][k][3],
                tmp_curr * u[i][j][k][4]
            };
            double vars_km1[4] = {
                tmp_prev * u[i][j][k-1][1],
                tmp_prev * u[i][j][k-1][2],
                tmp_prev * u[i][j][k-1][3],
                tmp_prev * u[i][j][k-1][4]
            };
            double diff[4];
            for (int n = 0; n < 4; n++) {
                diff[n] = vars_k[n] - vars_km1[n];
            }
            flux[i][j][k][1] = tz3 * diff[0];
            flux[i][j][k][2] = tz3 * diff[1];
            flux[i][j][k][3] = (4.0/3.0) * tz3 * diff[2];
            double vel_sq_k = vars_k[0]*vars_k[0] + vars_k[1]*vars_k[1] + vars_k[2]*vars_k[2];
            double vel_sq_km1 = vars_km1[0]*vars_km1[0] + vars_km1[1]*vars_km1[1] + vars_km1[2]*vars_km1[2];
            flux[i][j][k][4] = 0.5*(1.0 - 1.96)*tz3*(vel_sq_k - vel_sq_km1)
                             + (1.0/6.0)*tz3*(vars_k[2]*vars_k[2] - vars_km1[2]*vars_km1[2])
                             + 1.96*tz3*diff[3];
        }
        for (k = 2; k <= nz - 3; k++) {
            double u_im1[5], u_ip1[5];
            for (m = 0; m < 5; m++) {
                u_im1[m] = u[i][j][k-1][m];
                u_ip1[m] = u[i][j][k+1][m];
            }
            rsd[i][j][k][0] += dz1 * tz1 * (u_im1[0] - 2.0*u[i][j][k][0] + u_ip1[0]);
            rsd[i][j][k][1] += tz3 * 0.1 * (flux[i][j][k+1][1] - flux[i][j][k][1]) + dz2 * tz1 * (u_im1[1] - 2.0*u[i][j][k][1] + u_ip1[1]);
            rsd[i][j][k][2] += tz3 * 0.1 * (flux[i][j][k+1][2] - flux[i][j][k][2]) + dz3 * tz1 * (u_im1[2] - 2.0*u[i][j][k][2] + u_ip1[2]);
            rsd[i][j][k][3] += tz3 * 0.1 * (flux[i][j][k+1][3] - flux[i][j][k][3]) + dz4 * tz1 * (u_im1[3] - 2.0*u[i][j][k][3] + u_ip1[3]);
            rsd[i][j][k][4] += tz3 * 0.1 * (flux[i][j][k+1][4] - flux[i][j][k][4]) + dz5 * tz1 * (u_im1[4] - 2.0*u[i][j][k][4] + u_ip1[4]);
        }
        for (k = 1; k <= 2; k++) {
            for (m = 0; m < 5; m++) {
                if (k == 1) {
                    rsd[i][j][1][m] -= dssp * (5.0*u[i][j][1][m] - 4.0*u[i][j][2][m] + u[i][j][3][m]);
                } else {
                    rsd[i][j][2][m] -= dssp * (-4.0*u[i][j][1][m] + 6.0*u[i][j][2][m] - 4.0*u[i][j][3][m] + u[i][j][4][m]);
                }
            }
        }
        for (k = nz - 3; k <= nz - 2; k++) {
            for (m = 0; m < 5; m++) {
                if (k == nz - 3) {
                    rsd[i][j][k][m] -= dssp * (u[i][j][k-2][m] - 4.0*u[i][j][k-1][m] + 6.0*u[i][j][k][m] - 4.0*u[i][j][k+1][m]);
                } else {
                    rsd[i][j][k][m] -= dssp * (u[i][j][k-2][m] - 4.0*u[i][j][k-1][m] + 5.0*u[i][j][k][m]);
                }
            }
        }
        for (k = 4; k <= nz - 5; k += 4) {
            for (m = 0; m < 5; m++) {
                double s0 = u[i][j][k-2][m] - 4.0*u[i][j][k-1][m] + 6.0*u[i][j][k][m] - 4.0*u[i][j][k+1][m] + u[i][j][k+2][m];
                rsd[i][j][k][m] -= dssp * s0;
                if (k+1 <= nz-5) {
                    double s1 = u[i][j][k-1][m] - 4.0*u[i][j][k][m] + 6.0*u[i][j][k+1][m] - 4.0*u[i][j][k+2][m] + u[i][j][k+3][m];
                    rsd[i][j][k+1][m] -= dssp * s1;
                }
                if (k+2 <= nz-5) {
                    double s2 = u[i][j][k][m] - 4.0*u[i][j][k+1][m] + 6.0*u[i][j][k+2][m] - 4.0*u[i][j][k+3][m] + u[i][j][k+4][m];
                    rsd[i][j][k+2][m] -= dssp * s2;
                }
                if (k+3 <= nz-5) {
                    double s3 = u[i][j][k+1][m] - 4.0*u[i][j][k+2][m] + 6.0*u[i][j][k+3][m] - 4.0*u[i][j][k+4][m] + u[i][j][k+5][m];
                    rsd[i][j][k+3][m] -= dssp * s3;
                }
            }
        }
    }
}
}
