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
                frct[i][j][k][m] = frct[i][j][k][m] - tx2 * (flux[i + 1][j][k][m] - flux[i - 1][j][k][m]);
            }
        }
        for (i = ist; i <= L2; i += 2) {
            double tmp1 = 1. / rsd[i][j][k][0];
            double tmp2 = 1. / rsd[i - 1][j][k][0];
            u21i = tmp1 * rsd[i][j][k][1];
            u31i = tmp1 * rsd[i][j][k][2];
            u41i = tmp1 * rsd[i][j][k][3];
            u51i = tmp1 * rsd[i][j][k][4];
            u21im1 = tmp2 * rsd[i - 1][j][k][1];
            u31im1 = tmp2 * rsd[i - 1][j][k][2];
            u41im1 = tmp2 * rsd[i - 1][j][k][3];
            u51im1 = tmp2 * rsd[i - 1][j][k][4];
            double diff2 = u21i - u21im1;
            double diff3 = u31i - u31im1;
            double diff4 = u41i - u41im1;
            flux[i][j][k][1] = (4. / 3.) * tx3 * diff2;
            flux[i][j][k][2] = tx3 * diff3;
            flux[i][j][k][3] = tx3 * diff4;
            double sqsum_i = u21i * u21i + u31i * u31i + u41i * u41i;
            double sqsum_im1 = u21im1 * u21im1 + u31im1 * u31im1 + u41im1 * u41im1;
            flux[i][j][k][4] = 0.5 * (1. - 1.96) * tx3 * (sqsum_i - sqsum_im1) + (1. / 6.) * tx3 * (u21i * u21i - u21im1 * u21im1) + 1.96 * tx3 * (u51i - u51im1);
            if (i + 1 <= L2) {
                tmp1 = 1. / rsd[i + 1][j][k][0];
                tmp2 = 1. / rsd[i][j][k][0];
                double u21ip1 = tmp1 * rsd[i + 1][j][k][1];
                double u31ip1 = tmp1 * rsd[i + 1][j][k][2];
                double u41ip1 = tmp1 * rsd[i + 1][j][k][3];
                double u51ip1 = tmp1 * rsd[i + 1][j][k][4];
                double u21i_ = tmp2 * rsd[i][j][k][1];
                double u31i_ = tmp2 * rsd[i][j][k][2];
                double u41i_ = tmp2 * rsd[i][j][k][3];
                double u51i_ = tmp2 * rsd[i][j][k][4];
                double diff2b = u21ip1 - u21i_;
                double diff3b = u31ip1 - u31i_;
                double diff4b = u41ip1 - u41i_;
                flux[i + 1][j][k][1] = (4. / 3.) * tx3 * diff2b;
                flux[i + 1][j][k][2] = tx3 * diff3b;
                flux[i + 1][j][k][3] = tx3 * diff4b;
                double sqsum_ip1 = u21ip1 * u21ip1 + u31ip1 * u31ip1 + u41ip1 * u41ip1;
                double sqsum_i_ = u21i_ * u21i_ + u31i_ * u31i_ + u41i_ * u41i_;
                flux[i + 1][j][k][4] = 0.5 * (1. - 1.96) * tx3 * (sqsum_ip1 - sqsum_i_) + (1. / 6.) * tx3 * (u21ip1 * u21ip1 - u21i_ * u21i_) + 1.96 * tx3 * (u51ip1 - u51i_);
            }
        }
        for (i = ist; i <= iend; i++) {
            frct[i][j][k][0] = frct[i][j][k][0] + dx1 * tx1 * (rsd[i - 1][j][k][0] - 2. * rsd[i][j][k][0] + rsd[i + 1][j][k][0]);
            double f1 = tx3 * 0.1 * (flux[i + 1][j][k][1] - flux[i][j][k][1]);
            double f2 = tx3 * 0.1 * (flux[i + 1][j][k][2] - flux[i][j][k][2]);
            double f3 = tx3 * 0.1 * (flux[i + 1][j][k][3] - flux[i][j][k][3]);
            double f4 = tx3 * 0.1 * (flux[i + 1][j][k][4] - flux[i][j][k][4]);
            frct[i][j][k][1] = frct[i][j][k][1] + f1 + dx2 * tx1 * (rsd[i - 1][j][k][1] - 2. * rsd[i][j][k][1] + rsd[i + 1][j][k][1]);
            frct[i][j][k][2] = frct[i][j][k][2] + f2 + dx3 * tx1 * (rsd[i - 1][j][k][2] - 2. * rsd[i][j][k][2] + rsd[i + 1][j][k][2]);
            frct[i][j][k][3] = frct[i][j][k][3] + f3 + dx4 * tx1 * (rsd[i - 1][j][k][3] - 2. * rsd[i][j][k][3] + rsd[i + 1][j][k][3]);
            frct[i][j][k][4] = frct[i][j][k][4] + f4 + dx5 * tx1 * (rsd[i - 1][j][k][4] - 2. * rsd[i][j][k][4] + rsd[i + 1][j][k][4]);
        }
        for (m = 0; m < 5; m++) {
            frct[1][j][k][m] = frct[1][j][k][m] - dsspm * (+5. * rsd[1][j][k][m] - 4. * rsd[2][j][k][m] + rsd[3][j][k][m]);
            frct[2][j][k][m] = frct[2][j][k][m] - dsspm * (-4. * rsd[1][j][k][m] + 6. * rsd[2][j][k][m] - 4. * rsd[3][j][k][m] + rsd[4][j][k][m]);
        }
        ist1 = 3;
        iend1 = nx - 4;
        for (i = ist1; i <= iend1; i++) {
            double r_im2, r_im1, r_i, r_ip1, r_ip2;
            for (m = 0; m < 5; m++) {
                r_im2 = rsd[i - 2][j][k][m];
                r_im1 = rsd[i - 1][j][k][m];
                r_i   = rsd[i][j][k][m];
                r_ip1 = rsd[i + 1][j][k][m];
                r_ip2 = rsd[i + 2][j][k][m];
                frct[i][j][k][m] = frct[i][j][k][m] - dsspm * (r_im2 - 4.*r_im1 + 6.*r_i - 4.*r_ip1 + r_ip2);
            }
        }
        for (m = 0; m < 5; m++) {
            frct[nx - 3][j][k][m] = frct[nx - 3][j][k][m] - dsspm * (rsd[nx - 5][j][k][m] - 4. * rsd[nx - 4][j][k][m] + 6. * rsd[nx - 3][j][k][m] - 4. * rsd[nx - 2][j][k][m]);
            frct[nx - 2][j][k][m] = frct[nx - 2][j][k][m] - dsspm * (rsd[nx - 4][j][k][m] - 4. * rsd[nx - 3][j][k][m] + 5. * rsd[nx - 2][j][k][m]);
        }
    }
}
}
