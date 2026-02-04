#include <stdio.h>

extern  int ny;
extern  int nz;
extern  int ist;
extern  int iend;
extern  int jst;
extern  int jend;
extern  double ty1;
extern  double ty2;
extern  double ty3;
extern  double dy1;
extern  double dy2;
extern  double dy3;
extern  double dy4;
extern  double dy5;
extern  double rsd[64][65][65][5];
extern  double frct[64][65][65][5];
extern  double flux[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;
extern int L2;
extern int jst1;
extern int jend1;
extern double dsspm;
extern double tmp;
extern double u21j;
extern double u31j;
extern double u41j;
extern double u51j;
extern double u21jm1;
extern double u31jm1;
extern double u41jm1;
extern double u51jm1;



void loop(){
for (i = ist; i <= iend; i++) {
    for (k = 1; k <= nz - 2; k++) {
        // First, compute flux using forward differences to break dependency on prior j-loop
        for (j = jst1; j <= jend1; j++) {
            double tmp_j = 1. / rsd[i][j][k][0];
            double u21j_local = tmp_j * rsd[i][j][k][1];
            double u31j_local = tmp_j * rsd[i][j][k][2];
            double u41j_local = tmp_j * rsd[i][j][k][3];
            double u51j_local = tmp_j * rsd[i][j][k][4];

            double tmp_jm1 = 1. / rsd[i][j-1][k][0];
            double u21jm1_local = tmp_jm1 * rsd[i][j-1][k][1];
            double u31jm1_local = tmp_jm1 * rsd[i][j-1][k][2];
            double u41jm1_local = tmp_jm1 * rsd[i][j-1][k][3];
            double u51jm1_local = tmp_jm1 * rsd[i][j-1][k][4];

            flux[i][j][k][1] = ty3 * (u21j_local - u21jm1_local);
            flux[i][j][k][2] = (4. / 3.) * ty3 * (u31j_local - u31jm1_local);
            flux[i][j][k][3] = ty3 * (u41j_local - u41jm1_local);
            double vel_diff_j = (u21j_local * u21j_local + u31j_local * u31j_local + u41j_local * u41j_local) -
                                (u21jm1_local * u21jm1_local + u31jm1_local * u31jm1_local + u41jm1_local * u41jm1_local);
            double shear_term = (1. / 6.) * ty3 * (u31j_local * u31j_local - u31jm1_local * u31jm1_local);
            double energy_diff = 1.3999999999999999 * 1.3999999999999999 * ty3 * (u51j_local - u51jm1_local);
            flux[i][j][k][4] = 0.5 * (1. - 1.3999999999999999 * 1.3999999999999999) * ty3 * vel_diff_j + shear_term + energy_diff;
        }

        // Update frct with modified data flow: reverse order in j to change WAW pattern
        for (j = jend; j >= jst; j--) {
            for (m = 0; m < 5; m++) {
                frct[i][j][k][m] = frct[i][j][k][m] - ty2 * (flux[i][j + 1][k][m] - flux[i][j - 1][k][m]);
            }
        }

        // Introduce auxiliary array to eliminate write-after-read hazards
        double frct_temp[5];
        for (m = 0; m < 5; m++) {
            frct_temp[m] = 0.0;
        }

        for (j = jst; j <= jend; j++) {
            frct_temp[0] += dy1 * ty1 * (rsd[i][j - 1][k][0] - 2. * rsd[i][j][k][0] + rsd[i][j + 1][k][0]);
            frct_temp[1] += ty3 * 0.10000000000000001 * 1. * (flux[i][j + 1][k][1] - flux[i][j][k][1]) + dy2 * ty1 * (rsd[i][j - 1][k][1] - 2. * rsd[i][j][k][1] + rsd[i][j + 1][k][1]);
            frct_temp[2] += ty3 * 0.10000000000000001 * 1. * (flux[i][j + 1][k][2] - flux[i][j][k][2]) + dy3 * ty1 * (rsd[i][j - 1][k][2] - 2. * rsd[i][j][k][2] + rsd[i][j + 1][k][2]);
            frct_temp[3] += ty3 * 0.10000000000000001 * 1. * (flux[i][j + 1][k][3] - flux[i][j][k][3]) + dy4 * ty1 * (rsd[i][j - 1][k][3] - 2. * rsd[i][j][k][3] + rsd[i][j + 1][k][3]);
            frct_temp[4] += ty3 * 0.10000000000000001 * 1. * (flux[i][j + 1][k][4] - flux[i][j][k][4]) + dy5 * ty1 * (rsd[i][j - 1][k][4] - 2. * rsd[i][j][k][4] + rsd[i][j + 1][k][4]);
        }

        for (m = 0; m < 5; m++) {
            frct[i][jst][k][m] += frct_temp[m]; // Accumulate into boundary only to reduce WAW
        }

        // Apply smoothing with altered loop bounds and fused operations
        jst1 = 3;
        jend1 = ny - 4;
        for (j = jst1; j <= jend1; j++) {
            for (m = 0; m < 5; m++) {
                double stencil = rsd[i][j-2][k][m] - 4.*rsd[i][j-1][k][m] + 6.*rsd[i][j][k][m] - 4.*rsd[i][j+1][k][m] + rsd[i][j+2][k][m];
                frct[i][j][k][m] -= dsspm * stencil;
            }
        }

        // Handle boundaries with reduced temporary usage
        frct[i][1][k][0] -= dsspm * (+5. * rsd[i][1][k][0] - 4. * rsd[i][2][k][0] + rsd[i][3][k][0]);
        frct[i][2][k][0] -= dsspm * (-4. * rsd[i][1][k][0] + 6. * rsd[i][2][k][0] - 4. * rsd[i][3][k][0] + rsd[i][4][k][0]);

        frct[i][ny-3][k][0] -= dsspm * (rsd[i][ny-5][k][0] - 4.*rsd[i][ny-4][k][0] + 6.*rsd[i][ny-3][k][0] - 4.*rsd[i][ny-2][k][0]);
        frct[i][ny-2][k][0] -= dsspm * (rsd[i][ny-4][k][0] - 4.*rsd[i][ny-3][k][0] + 5.*rsd[i][ny-2][k][0]);

        // Replicate for m=1..4 with unrolled structure to increase ILP
        for (m = 1; m < 5; m++) {
            frct[i][1][k][m] -= dsspm * (+5. * rsd[i][1][k][m] - 4. * rsd[i][2][k][m] + rsd[i][3][k][m]);
            frct[i][2][k][m] -= dsspm * (-4. * rsd[i][1][k][m] + 6. * rsd[i][2][k][m] - 4. * rsd[i][3][k][m] + rsd[i][4][k][m]);
            frct[i][ny-3][k][m] -= dsspm * (rsd[i][ny-5][k][m] - 4.*rsd[i][ny-4][k][m] + 6.*rsd[i][ny-3][k][m] - 4.*rsd[i][ny-2][k][m]);
            frct[i][ny-2][k][m] -= dsspm * (rsd[i][ny-4][k][m] - 4.*rsd[i][ny-3][k][m] + 5.*rsd[i][ny-2][k][m]);
        }
    }
}
}
