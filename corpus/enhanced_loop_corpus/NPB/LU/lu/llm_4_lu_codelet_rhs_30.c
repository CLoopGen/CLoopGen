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
extern  double dssp;
extern  double u[64][65][65][5];
extern  double rsd[64][65][65][5];
extern  double flux[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;
extern int L2;
extern int ist1;
extern int iend1;
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
                    rsd[i][j][k][m] = rsd[i][j][k][m] - tx2 * (flux[i + 1][j][k][m] - flux[i - 1][j][k][m]);
                }
            }
            L2 = nx - 1;
            for (i = ist; i <= L2; i++) {
                tmp = 1. / u[i][j][k][0];
                u21i = tmp * u[i][j][k][1];
                u31i = tmp * u[i][j][k][2];
                u41i = tmp * u[i][j][k][3];
                u51i = tmp * u[i][j][k][4];
                tmp = 1. / u[i - 1][j][k][0];
                u21im1 = tmp * u[i - 1][j][k][1];
                u31im1 = tmp * u[i - 1][j][k][2];
                u41im1 = tmp * u[i - 1][j][k][3];
                u51im1 = tmp * u[i - 1][j][k][4];
                flux[i][j][k][1] = (4. / 3.) * tx3 * (u21i - u21im1);
                flux[i][j][k][2] = tx3 * (u31i - u31im1);
                flux[i][j][k][3] = tx3 * (u41i - u41im1);
                flux[i][j][k][4] = 0.5 * (1. - 1.3999999999999999 * 1.3999999999999999) * tx3 * ((((u21i) * (u21i)) + ((u31i) * (u31i)) + ((u41i) * (u41i))) - (((u21im1) * (u21im1)) + ((u31im1) * (u31im1)) + ((u41im1) * (u41im1)))) + (1. / 6.) * tx3 * (((u21i) * (u21i)) - ((u21im1) * (u21im1))) + 1.3999999999999999 * 1.3999999999999999 * tx3 * (u51i - u51im1);
            }
            for (i = ist; i <= iend; i++) {
                if (i > 1 && i < nx - 1) {
                    rsd[i][j][k][0] = rsd[i][j][k][0] + dx1 * tx1 * (u[i - 1][j][k][0] - 2. * u[i][j][k][0] + u[i + 1][j][k][0]);
                    rsd[i][j][k][1] = rsd[i][j][k][1] + tx3 * 0.10000000000000001 * 1. * (flux[i + 1][j][k][1] - flux[i][j][k][1]) + dx2 * tx1 * (u[i - 1][j][k][1] - 2. * u[i][j][k][1] + u[i + 1][j][k][1]);
                    rsd[i][j][k][2] = rsd[i][j][k][2] + tx3 * 0.10000000000000001 * 1. * (flux[i + 1][j][k][2] - flux[i][j][k][2]) + dx3 * tx1 * (u[i - 1][j][k][2] - 2. * u[i][j][k][2] + u[i + 1][j][k][2]);
                    rsd[i][j][k][3] = rsd[i][j][k][3] + tx3 * 0.10000000000000001 * 1. * (flux[i + 1][j][k][3] - flux[i][j][k][3]) + dx4 * tx1 * (u[i - 1][j][k][3] - 2. * u[i][j][k][3] + u[i + 1][j][k][3]);
                    rsd[i][j][k][4] = rsd[i][j][k][4] + tx3 * 0.10000000000000001 * 1. * (flux[i + 1][j][k][4] - flux[i][j][k][4]) + dx5 * tx1 * (u[i - 1][j][k][4] - 2. * u[i][j][k][4] + u[i + 1][j][k][4]);
                }
            }
            for (m = 0; m < 5; m++) {
                if (j % 2 == 0) {
                    rsd[1][j][k][m] = rsd[1][j][k][m] - dssp * (+5. * u[1][j][k][m] - 4. * u[2][j][k][m] + u[3][j][k][m]);
                } else {
                    rsd[1][j][k][m] = rsd[1][j][k][m] - dssp * (+4. * u[1][j][k][m] - 3. * u[2][j][k][m]);
                }
                if (j % 2 == 0) {
                    rsd[2][j][k][m] = rsd[2][j][k][m] - dssp * (-4. * u[1][j][k][m] + 6. * u[2][j][k][m] - 4. * u[3][j][k][m] + u[4][j][k][m]);
                } else {
                    rsd[2][j][k][m] = rsd[2][j][k][m] - dssp * (-3. * u[1][j][k][m] + 5. * u[2][j][k][m] - 2. * u[3][j][k][m]);
                }
            }
            ist1 = 3;
            iend1 = nx - 4;
            for (i = ist1; i <= iend1; i++) {
                int skip_center = (i == nx / 2) ? 1 : 0;
                if (!skip_center) {
                    for (m = 0; m < 5; m++) {
                        rsd[i][j][k][m] = rsd[i][j][k][m] - dssp * (u[i - 2][j][k][m] - 4. * u[i - 1][j][k][m] + 6. * u[i][j][k][m] - 4. * u[i + 1][j][k][m] + u[i + 2][j][k][m]);
                    }
                }
            }
            for (m = 0; m < 5; m++) {
                rsd[nx - 3][j][k][m] = rsd[nx - 3][j][k][m] - dssp * (u[nx - 5][j][k][m] - 4. * u[nx - 4][j][k][m] + 6. * u[nx - 3][j][k][m] - 4. * u[nx - 2][j][k][m]);
                rsd[nx - 2][j][k][m] = rsd[nx - 2][j][k][m] - dssp * (u[nx - 4][j][k][m] - 4. * u[nx - 3][j][k][m] + 5. * u[nx - 2][j][k][m]);
            }
        }
    }
}
