#include <stdio.h>

extern  int nx;
extern  int nz;
extern  int ist;
extern  int iend;
extern  int jst;
extern  int jend;
extern  double tx1;
extern  double tx2;
extern  double tx3;
extern  double dx1;
extern  double dx2;
extern  double dx3;
extern  double dx4;
extern  double dx5;
extern  double rsd[64][65][65][5];
extern  double frct[64][65][65][5];
extern  double flux[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;
extern int L2;
extern int ist1;
extern int iend1;
extern double dsspm;
extern double tmp;
extern double u21i;
extern double u31i;
extern double u41i;
extern double u51i;
extern double u21im1;
extern double u31im1;
extern double u41im1;
extern double u51im1;



void loop(){
for (j = jst; j <= jend; j++) {
    for (k = 1; k <= nz - 2; k++) {
        for (i = ist; i <= iend; i++) {
            for (m = 0; m < 5; m++) {
                double diff = flux[i + 1][j][k][m] - flux[i - 1][j][k][m];
                if (diff > 0 || m % 2 == 0) {
                    frct[i][j][k][m] -= tx2 * diff;
                } else {
                    frct[i][j][k][m] += tx2 * diff * 0.5;
                }
            }
        }
        for (i = ist; i <= L2; i++) {
            if (rsd[i][j][k][0] != 0 && rsd[i - 1][j][k][0] != 0) {
                tmp = 1. / rsd[i][j][k][0];
                u21i = tmp * rsd[i][j][k][1];
                u31i = tmp * rsd[i][j][k][2];
                u41i = tmp * rsd[i][j][k][3];
                u51i = tmp * rsd[i][j][k][4];
                tmp = 1. / rsd[i - 1][j][k][0];
                u21im1 = tmp * rsd[i - 1][j][k][1];
                u31im1 = tmp * rsd[i - 1][j][k][2];
                u41im1 = tmp * rsd[i - 1][j][k][3];
                u51im1 = tmp * rsd[i - 1][j][k][4];

                flux[i][j][k][1] = (4. / 3.) * tx3 * (u21i - u21im1);
                flux[i][j][k][2] = tx3 * (u31i - u31im1);
                flux[i][j][k][3] = tx3 * (u41i - u41im1);
                flux[i][j][k][4] = 0.5 * (1. - 1.3999999999999999 * 1.3999999999999999) * tx3 * (
                    (u21i*u21i + u31i*u31i + u41i*u41i) - 
                    (u21im1*u21im1 + u31im1*u31im1 + u41im1*u41im1)
                ) + (1./6.) * tx3 * (u21i*u21i - u21im1*u21im1) + 
                  1.3999999999999999*1.3999999999999999 * tx3 * (u51i - u51im1);
            } else {
                for (int m = 1; m < 5; m++) {
                    flux[i][j][k][m] = 0.0;
                }
            }
        }
        for (i = ist; i <= iend; i++) {
            double center, left, right;
            center = rsd[i][j][k][0];
            left = (i > 0) ? rsd[i-1][j][k][0] : center;
            right = (i < nx-1) ? rsd[i+1][j][k][0] : center;
            frct[i][j][k][0] += dx1 * tx1 * (left - 2.*center + right);

            for (m = 1; m < 5; m++) {
                center = rsd[i][j][k][m];
                left = (i > 0) ? rsd[i-1][j][k][m] : center;
                right = (i < nx-1) ? rsd[i+1][j][k][m] : center;
                double laplacian = left - 2.*center + right;
                double flux_diff = (i < nx-1) ? (flux[i+1][j][k][m] - flux[i][j][k][m]) : 0.0;
                frct[i][j][k][m] += tx3 * 0.10000000000000001 * flux_diff + 
                                    ((m==1)?dx2:((m==2)?dx3:((m==3)?dx4:dx5))) * tx1 * laplacian;
            }
        }
        ist1 = 3;
        iend1 = nx - 4;
        for (m = 0; m < 5; m++) {
            if (ist1 <= iend1) {
                frct[1][j][k][m] -= dsspm * (+5. * rsd[1][j][k][m] - 4. * rsd[2][j][k][m] + rsd[3][j][k][m]);
                frct[2][j][k][m] -= dsspm * (-4. * rsd[1][j][k][m] + 6. * rsd[2][j][k][m] - 4. * rsd[3][j][k][m] + rsd[4][j][k][m]);
                for (i = ist1; i <= iend1; i++) {
                    frct[i][j][k][m] -= dsspm * (rsd[i-2][j][k][m] - 4.*rsd[i-1][j][k][m] + 6.*rsd[i][j][k][m] - 4.*rsd[i+1][j][k][m] + rsd[i+2][j][k][m]);
                }
                frct[nx-3][j][k][m] -= dsspm * (rsd[nx-5][j][k][m] - 4.*rsd[nx-4][j][k][m] + 6.*rsd[nx-3][j][k][m] - 4.*rsd[nx-2][j][k][m]);
                frct[nx-2][j][k][m] -= dsspm * (rsd[nx-4][j][k][m] - 4.*rsd[nx-3][j][k][m] + 5.*rsd[nx-2][j][k][m]);
            } else {
                for (i = 1; i <= nx; i++) {
                    if (i >= 1 && i <= nx-2) {
                        frct[i][j][k][m] -= dsspm * rsd[i][j][k][m];
                    }
                }
            }
        }
    }
}
}
