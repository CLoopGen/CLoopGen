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
for (j = jst; j <= jend; j += 2) {
    for (k = 1; k <= nz - 2; k++) {
        for (i = ist; i <= iend; i++) {
            double temp[5];
            for (m = 0; m < 5; m++) {
                temp[m] = frct[i][j][k][m] - tx2 * (flux[i + 1][j][k][m] - flux[i - 1][j][k][m]);
            }
            for (m = 0; m < 5; m++) {
                frct[i][j][k][m] = temp[m];
            }
        }
        for (i = ist + 1; i <= L2; i++) {
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
            double v2 = u21i - u21im1;
            double v3 = u31i - u31im1;
            double v4 = u41i - u41im1;
            double e_diff = ((u21i * u21i + u31i * u31i + u41i * u41i) - (u21im1 * u21im1 + u31im1 * u31im1 + u41im1 * u41im1));
            double u2_sq_diff = u21i * u21i - u21im1 * u21im1;
            flux[i][j][k][1] = (4.0/3.0) * tx3 * v2;
            flux[i][j][k][2] = tx3 * v3;
            flux[i][j][k][3] = tx3 * v4;
            flux[i][j][k][4] = 0.5 * (1. - 1.96) * tx3 * e_diff + (1./6.) * tx3 * u2_sq_diff + 1.96 * tx3 * (u51i - u51im1);
        }
        for (i = ist; i <= iend; i++) {
            double lap0 = rsd[i - 1][j][k][0] - 2. * rsd[i][j][k][0] + rsd[i + 1][j][k][0];
            double lap1 = rsd[i - 1][j][k][1] - 2. * rsd[i][j][k][1] + rsd[i + 1][j][k][1];
            double lap2 = rsd[i - 1][j][k][2] - 2. * rsd[i][j][k][2] + rsd[i + 1][j][k][2];
            double lap3 = rsd[i - 1][j][k][3] - 2. * rsd[i][j][k][3] + rsd[i + 1][j][k][3];
            double lap4 = rsd[i - 1][j][k][4] - 2. * rsd[i][j][k][4] + rsd[i + 1][j][k][4];
            frct[i][j][k][0] += dx1 * tx1 * lap0;
            frct[i][j][k][1] += tx3 * 0.1 * (flux[i + 1][j][k][1] - flux[i][j][k][1]) + dx2 * tx1 * lap1;
            frct[i][j][k][2] += tx3 * 0.1 * (flux[i + 1][j][k][2] - flux[i][j][k][2]) + dx3 * tx1 * lap2;
            frct[i][j][k][3] += tx3 * 0.1 * (flux[i + 1][j][k][3] - flux[i][j][k][3]) + dx4 * tx1 * lap3;
            frct[i][j][k][4] += tx3 * 0.1 * (flux[i + 1][j][k][4] - flux[i][j][k][4]) + dx5 * tx1 * lap4;
        }
        for (m = 0; m < 5; m++) {
            frct[1][j][k][m] -= dsspm * (5. * rsd[1][j][k][m] - 4. * rsd[2][j][k][m] + rsd[3][j][k][m]);
            frct[2][j][k][m] -= dsspm * (-4. * rsd[1][j][k][m] + 6. * rsd[2][j][k][m] - 4. * rsd[3][j][k][m] + rsd[4][j][k][m]);
        }
        for (i = 3; i <= nx - 4; i++) {
            for (m = 0; m < 5; m++) {
                frct[i][j][k][m] -= dsspm * (rsd[i-2][j][k][m] - 4.*rsd[i-1][j][k][m] + 6.*rsd[i][j][k][m] - 4.*rsd[i+1][j][k][m] + rsd[i+2][j][k][m]);
            }
        }
        for (m = 0; m < 5; m++) {
            frct[nx-3][j][k][m] -= dsspm * (rsd[nx-5][j][k][m] - 4.*rsd[nx-4][j][k][m] + 6.*rsd[nx-3][j][k][m] - 4.*rsd[nx-2][j][k][m]);
            frct[nx-2][j][k][m] -= dsspm * (rsd[nx-4][j][k][m] - 4.*rsd[nx-3][j][k][m] + 5.*rsd[nx-2][j][k][m]);
        }
    }
    if (j + 1 <= jend) {
        for (k = 1; k <= nz - 2; k++) {
            for (i = ist; i <= iend; i++) {
                for (m = 0; m < 5; m++) {
                    frct[i][j+1][k][m] = frct[i][j+1][k][m] - tx2 * (flux[i + 1][j+1][k][m] - flux[i - 1][j+1][k][m]);
                }
            }
            for (i = ist; i <= L2; i++) {
                tmp = 1. / rsd[i][j+1][k][0];
                u21i = tmp * rsd[i][j+1][k][1];
                u31i = tmp * rsd[i][j+1][k][2];
                u41i = tmp * rsd[i][j+1][k][3];
                u51i = tmp * rsd[i][j+1][k][4];
                tmp = 1. / rsd[i - 1][j+1][k][0];
                u21im1 = tmp * rsd[i - 1][j+1][k][1];
                u31im1 = tmp * rsd[i - 1][j+1][k][2];
                u41im1 = tmp * rsd[i - 1][j+1][k][3];
                u51im1 = tmp * rsd[i - 1][j+1][k][4];
                flux[i][j+1][k][1] = (4. / 3.) * tx3 * (u21i - u21im1);
                flux[i][j+1][k][2] = tx3 * (u31i - u31im1);
                flux[i][j+1][k][3] = tx3 * (u41i - u41im1);
                flux[i][j+1][k][4] = 0.5 * (1. - 1.96) * tx3 * ((u21i*u21i + u31i*u31i + u41i*u41i) - (u21im1*u21im1 + u31im1*u31im1 + u41im1*u41im1)) + (1./6.)*tx3*(u21i*u21i - u21im1*u21im1) + 1.96*tx3*(u51i - u51im1);
            }
            for (i = ist; i <= iend; i++) {
                frct[i][j+1][k][0] += dx1 * tx1 * (rsd[i-1][j+1][k][0] - 2.*rsd[i][j+1][k][0] + rsd[i+1][j+1][k][0]);
                frct[i][j+1][k][1] += tx3 * 0.1 * (flux[i+1][j+1][k][1] - flux[i][j+1][k][1]) + dx2 * tx1 * (rsd[i-1][j+1][k][1] - 2.*rsd[i][j+1][k][1] + rsd[i+1][j+1][k][1]);
                frct[i][j+1][k][2] += tx3 * 0.1 * (flux[i+1][j+1][k][2] - flux[i][j+1][k][2]) + dx3 * tx1 * (rsd[i-1][j+1][k][2] - 2.*rsd[i][j+1][k][2] + rsd[i+1][j+1][k][2]);
                frct[i][j+1][k][3] += tx3 * 0.1 * (flux[i+1][j+1][k][3] - flux[i][j+1][k][3]) + dx4 * tx1 * (rsd[i-1][j+1][k][3] - 2.*rsd[i][j+1][k][3] + rsd[i+1][j+1][k][3]);
                frct[i][j+1][k][4] += tx3 * 0.1 * (flux[i+1][j+1][k][4] - flux[i][j+1][k][4]) + dx5 * tx1 * (rsd[i-1][j+1][k][4] - 2.*rsd[i][j+1][k][4] + rsd[i+1][j+1][k][4]);
            }
            for (m = 0; m < 5; m++) {
                frct[1][j+1][k][m] -= dsspm * (5.*rsd[1][j+1][k][m] - 4.*rsd[2][j+1][k][m] + rsd[3][j+1][k][m]);
                frct[2][j+1][k][m] -= dsspm * (-4.*rsd[1][j+1][k][m] + 6.*rsd[2][j+1][k][m] - 4.*rsd[3][j+1][k][m] + rsd[4][j+1][k][m]);
            }
            for (i = 3; i <= nx - 4; i++) {
                for (m = 0; m < 5; m++) {
                    frct[i][j+1][k][m] -= dsspm * (rsd[i-2][j+1][k][m] - 4.*rsd[i-1][j+1][k][m] + 6.*rsd[i][j+1][k][m] - 4.*rsd[i+1][j+1][k][m] + rsd[i+2][j+1][k][m]);
                }
            }
            for (m = 0; m < 5; m++) {
                frct[nx-3][j+1][k][m] -= dsspm * (rsd[nx-5][j+1][k][m] - 4.*rsd[nx-4][j+1][k][m] + 6.*rsd[nx-3][j+1][k][m] - 4.*rsd[nx-2][j+1][k][m]);
                frct[nx-2][j+1][k][m] -= dsspm * (rsd[nx-4][j+1][k][m] - 4.*rsd[nx-3][j+1][k][m] + 5.*rsd[nx-2][j+1][k][m]);
            }
        }
    }
}
}
