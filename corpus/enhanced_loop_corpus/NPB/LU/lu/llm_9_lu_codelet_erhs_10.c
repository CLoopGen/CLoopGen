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
for (i = ist; i <= iend; i += 2) {
    for (j = jst; j <= jend; j += 2) {
        for (k = 0; k < nz; k++) {
            for (int ii = 0; ii < 2 && (i + ii) <= iend; ii++) {
                for (int jj = 0; jj < 2 && (j + jj) <= jend; jj++) {
                    int ci = i + ii;
                    int cj = j + jj;

                    flux[ci][cj][k][0] = rsd[ci][cj][k][3];
                    double rho_inv = 1.0 / rsd[ci][cj][k][0];
                    double u41_loc = rsd[ci][cj][k][3] * rho_inv;
                    double q_loc = 0.5 * (rsd[ci][cj][k][1]*rsd[ci][cj][k][1] +
                                          rsd[ci][cj][k][2]*rsd[ci][cj][k][2] +
                                          rsd[ci][cj][k][3]*rsd[ci][cj][k][3]) * rho_inv;

                    flux[ci][cj][k][1] = rsd[ci][cj][k][1] * u41_loc;
                    flux[ci][cj][k][2] = rsd[ci][cj][k][2] * u41_loc;
                    flux[ci][cj][k][3] = rsd[ci][cj][k][3] * u41_loc + 0.4 * (rsd[ci][cj][k][4] - q_loc);
                    flux[ci][cj][k][4] = (1.4 * rsd[ci][cj][k][4] - 0.4 * q_loc) * u41_loc;
                }
            }
        }

        for (k = 1; k <= nz - 2; k++) {
            for (int ii = 0; ii < 2 && (i + ii) <= iend; ii++) {
                for (int jj = 0; jj < 2 && (j + jj) <= jend; jj++) {
                    int ci = i + ii;
                    int cj = j + jj;
                    for (m = 0; m < 5; m++) {
                        frct[ci][cj][k][m] -= tz2 * (flux[ci][cj][k+1][m] - flux[ci][cj][k-1][m]);
                    }
                }
            }
        }

        for (k = 1; k < nz; k++) {
            for (int ii = 0; ii < 2 && (i + ii) <= iend; ii++) {
                for (int jj = 0; jj < 2 && (j + jj) <= jend; jj++) {
                    int ci = i + ii;
                    int cj = j + jj;

                    double tmp_k   = 1.0 / rsd[ci][cj][k][0];
                    double tmp_km1 = 1.0 / rsd[ci][cj][k-1][0];

                    double u21k  = tmp_k   * rsd[ci][cj][k][1];
                    double u31k  = tmp_k   * rsd[ci][cj][k][2];
                    double u41k  = tmp_k   * rsd[ci][cj][k][3];
                    double u51k  = tmp_k   * rsd[ci][cj][k][4];
                    double u21km1 = tmp_km1 * rsd[ci][cj][k-1][1];
                    double u31km1 = tmp_km1 * rsd[ci][cj][k-1][2];
                    double u41km1 = tmp_km1 * rsd[ci][cj][k-1][3];
                    double u51km1 = tmp_km1 * rsd[ci][cj][k-1][4];

                    flux[ci][cj][k][1] = tz3 * (u21k - u21km1);
                    flux[ci][cj][k][2] = tz3 * (u31k - u31km1);
                    flux[ci][cj][k][3] = (4.0/3.0) * tz3 * (u41k - u41km1);
                    flux[ci][cj][k][4] = 0.5*(1.0 - 1.96)*tz3*((u21k*u21k + u31k*u31k + u41k*u41k) - (u21km1*u21km1 + u31km1*u31km1 + u41km1*u41km1))
                                       + (1.0/6.0)*tz3*(u41k*u41k - u41km1*u41km1) + 1.96*tz3*(u51k - u51km1);
                }
            }
        }

        for (k = 1; k <= nz - 2; k++) {
            for (int ii = 0; ii < 2 && (i + ii) <= iend; ii++) {
                for (int jj = 0; jj < 2 && (j + jj) <= jend; jj++) {
                    int ci = i + ii;
                    int cj = j + jj;

                    double lap0 = rsd[ci][cj][k+1][0] - 2.0*rsd[ci][cj][k][0] + rsd[ci][cj][k-1][0];
                    double lap1 = rsd[ci][cj][k+1][1] - 2.0*rsd[ci][cj][k][1] + rsd[ci][cj][k-1][1];
                    double lap2 = rsd[ci][cj][k+1][2] - 2.0*rsd[ci][cj][k][2] + rsd[ci][cj][k-1][2];
                    double lap3 = rsd[ci][cj][k+1][3] - 2.0*rsd[ci][cj][k][3] + rsd[ci][cj][k-1][3];
                    double lap4 = rsd[ci][cj][k+1][4] - 2.0*rsd[ci][cj][k][4] + rsd[ci][cj][k-1][4];

                    frct[ci][cj][k][0] += dz1 * tz1 * lap0;
                    frct[ci][cj][k][1] += tz3 * 0.1 * (flux[ci][cj][k+1][1] - flux[ci][cj][k][1]) + dz2 * tz1 * lap1;
                    frct[ci][cj][k][2] += tz3 * 0.1 * (flux[ci][cj][k+1][2] - flux[ci][cj][k][2]) + dz3 * tz1 * lap2;
                    frct[ci][cj][k][3] += tz3 * 0.1 * (flux[ci][cj][k+1][3] - flux[ci][cj][k][3]) + dz4 * tz1 * lap3;
                    frct[ci][cj][k][4] += tz3 * 0.1 * (flux[ci][cj][k+1][4] - flux[ci][cj][k][4]) + dz5 * tz1 * lap4;
                }
            }
        }

        for (int ii = 0; ii < 2 && (i + ii) <= iend; ii++) {
            for (int jj = 0; jj < 2 && (j + jj) <= jend; jj++) {
                int ci = i + ii;
                int cj = j + jj;
                for (m = 0; m < 5; m++) {
                    if (1 <= nz - 3) frct[ci][cj][1][m] -= dsspm * (+5.0*rsd[ci][cj][1][m] - 4.0*rsd[ci][cj][2][m] + rsd[ci][cj][3][m]);
                    if (2 <= nz - 3) frct[ci][cj][2][m] -= dsspm * (-4.0*rsd[ci][cj][1][m] + 6.0*rsd[ci][cj][2][m] - 4.0*rsd[ci][cj][3][m] + rsd[ci][cj][4][m]);
                }
            }
        }

        for (k = 3; k <= nz - 4; k++) {
            for (int ii = 0; ii < 2 && (i + ii) <= iend; ii++) {
                for (int jj = 0; jj < 2 && (j + jj) <= jend; jj++) {
                    int ci = i + ii;
                    int cj = j + jj;
                    for (m = 0; m < 5; m++) {
                        frct[ci][cj][k][m] -= dsspm * (rsd[ci][cj][k-2][m] - 4.0*rsd[ci][cj][k-1][m] + 6.0*rsd[ci][cj][k][m] - 4.0*rsd[ci][cj][k+1][m] + rsd[ci][cj][k+2][m]);
                    }
                }
            }
        }

        for (int ii = 0; ii < 2 && (i + ii) <= iend; ii++) {
            for (int jj = 0; jj < 2 && (j + jj) <= jend; jj++) {
                int ci = i + ii;
                int cj = j + jj;
                for (m = 0; m < 5; m++) {
                    if (nz - 3 >= 1) frct[ci][cj][nz-3][m] -= dsspm * (rsd[ci][cj][nz-5][m] - 4.0*rsd[ci][cj][nz-4][m] + 6.0*rsd[ci][cj][nz-3][m] - 4.0*rsd[ci][cj][nz-2][m]);
                    if (nz - 2 >= 1) frct[ci][cj][nz-2][m] -= dsspm * (rsd[ci][cj][nz-4][m] - 4.0*rsd[ci][cj][nz-3][m] + 5.0*rsd[ci][cj][nz-2][m]);
                }
            }
        }
    }
}
}
