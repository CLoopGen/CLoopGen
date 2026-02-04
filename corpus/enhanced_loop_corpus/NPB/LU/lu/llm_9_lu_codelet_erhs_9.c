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
for (i = ist; i <= iend; i += 2) {
    for (k = 1; k <= nz - 2; k++) {
        for (j = jst; j <= jend; j++) {
            for (m = 0; m < 5; m++) {
                double delta_flux = flux[i][j + 1][k][m] - flux[i][j - 1][k][m];
                frct[i][j][k][m] -= ty2 * delta_flux;
                if (i + 1 <= iend) {
                    double delta_flux_next = flux[i + 1][j + 1][k][m] - flux[i + 1][j - 1][k][m];
                    frct[i + 1][j][k][m] -= ty2 * delta_flux_next;
                }
            }
        }
        for (j = jst; j <= L2; j++) {
            tmp = 1.0 / rsd[i][j][k][0];
            u21j = tmp * rsd[i][j][k][1];
            u31j = tmp * rsd[i][j][k][2];
            u41j = tmp * rsd[i][j][k][3];
            u51j = tmp * rsd[i][j][k][4];
            tmp = 1.0 / rsd[i][j - 1][k][0];
            u21jm1 = tmp * rsd[i][j - 1][k][1];
            u31jm1 = tmp * rsd[i][j - 1][k][2];
            u41jm1 = tmp * rsd[i][j - 1][k][3];
            u51jm1 = tmp * rsd[i][j - 1][k][4];

            flux[i][j][k][1] = ty3 * (u21j - u21jm1);
            flux[i][j][k][2] = (4.0 / 3.0) * ty3 * (u31j - u31jm1);
            flux[i][j][k][3] = ty3 * (u41j - u41jm1);
            double u2_sq_j = u21j * u21j, u3_sq_j = u31j * u31j, u4_sq_j = u41j * u41j;
            double u2_sq_jm1 = u21jm1 * u21jm1, u3_sq_jm1 = u31jm1 * u31jm1, u4_sq_jm1 = u41jm1 * u41jm1;
            flux[i][j][k][4] = 0.5 * (1.0 - 1.96) * ty3 * ((u2_sq_j + u3_sq_j + u4_sq_j) - (u2_sq_jm1 + u3_sq_jm1 + u4_sq_jm1))
                             + (1.0 / 6.0) * ty3 * (u3_sq_j - u3_sq_jm1)
                             + 1.96 * ty3 * (u51j - u51jm1);

            if (i + 1 <= iend) {
                tmp = 1.0 / rsd[i + 1][j][k][0];
                double u21j_n = tmp * rsd[i + 1][j][k][1];
                double u31j_n = tmp * rsd[i + 1][j][k][2];
                double u41j_n = tmp * rsd[i + 1][j][k][3];
                double u51j_n = tmp * rsd[i + 1][j][k][4];
                tmp = 1.0 / rsd[i + 1][j - 1][k][0];
                double u21jm1_n = tmp * rsd[i + 1][j - 1][k][1];
                double u31jm1_n = tmp * rsd[i + 1][j - 1][k][2];
                double u41jm1_n = tmp * rsd[i + 1][j - 1][k][3];
                double u51jm1_n = tmp * rsd[i + 1][j - 1][k][4];

                flux[i + 1][j][k][1] = ty3 * (u21j_n - u21jm1_n);
                flux[i + 1][j][k][2] = (4.0 / 3.0) * ty3 * (u31j_n - u31jm1_n);
                flux[i + 1][j][k][3] = ty3 * (u41j_n - u41jm1_n);
                double u2_sq_j_n = u21j_n * u21j_n, u3_sq_j_n = u31j_n * u31j_n, u4_sq_j_n = u41j_n * u41j_n;
                double u2_sq_jm1_n = u21jm1_n * u21jm1_n, u3_sq_jm1_n = u31jm1_n * u31jm1_n, u4_sq_jm1_n = u41jm1_n * u41jm1_n;
                flux[i + 1][j][k][4] = 0.5 * (1.0 - 1.96) * ty3 * ((u2_sq_j_n + u3_sq_j_n + u4_sq_j_n) - (u2_sq_jm1_n + u3_sq_jm1_n + u4_sq_jm1_n))
                                     + (1.0 / 6.0) * ty3 * (u3_sq_j_n - u3_sq_jm1_n)
                                     + 1.96 * ty3 * (u51j_n - u51jm1_n);
            }
        }
        for (j = jst; j <= jend; j++) {
            frct[i][j][k][0] += dy1 * ty1 * (rsd[i][j - 1][k][0] - 2.0 * rsd[i][j][k][0] + rsd[i][j + 1][k][0]);
            frct[i][j][k][1] += ty3 * 0.1 * (flux[i][j + 1][k][1] - flux[i][j][k][1]) + dy2 * ty1 * (rsd[i][j - 1][k][1] - 2.0 * rsd[i][j][k][1] + rsd[i][j + 1][k][1]);
            frct[i][j][k][2] += ty3 * 0.1 * (flux[i][j + 1][k][2] - flux[i][j][k][2]) + dy3 * ty1 * (rsd[i][j - 1][k][2] - 2.0 * rsd[i][j][k][2] + rsd[i][j + 1][k][2]);
            frct[i][j][k][3] += ty3 * 0.1 * (flux[i][j + 1][k][3] - flux[i][j][k][3]) + dy4 * ty1 * (rsd[i][j - 1][k][3] - 2.0 * rsd[i][j][k][3] + rsd[i][j + 1][k][3]);
            frct[i][j][k][4] += ty3 * 0.1 * (flux[i][j + 1][k][4] - flux[i][j][k][4]) + dy5 * ty1 * (rsd[i][j - 1][k][4] - 2.0 * rsd[i][j][k][4] + rsd[i][j + 1][k][4]);

            if (i + 1 <= iend) {
                frct[i + 1][j][k][0] += dy1 * ty1 * (rsd[i + 1][j - 1][k][0] - 2.0 * rsd[i + 1][j][k][0] + rsd[i + 1][j + 1][k][0]);
                frct[i + 1][j][k][1] += ty3 * 0.1 * (flux[i + 1][j + 1][k][1] - flux[i + 1][j][k][1]) + dy2 * ty1 * (rsd[i + 1][j - 1][k][1] - 2.0 * rsd[i + 1][j][k][1] + rsd[i + 1][j + 1][k][1]);
                frct[i + 1][j][k][2] += ty3 * 0.1 * (flux[i + 1][j + 1][k][2] - flux[i + 1][j][k][2]) + dy3 * ty1 * (rsd[i + 1][j - 1][k][2] - 2.0 * rsd[i + 1][j][k][2] + rsd[i + 1][j + 1][k][2]);
                frct[i + 1][j][k][3] += ty3 * 0.1 * (flux[i + 1][j + 1][k][3] - flux[i + 1][j][k][3]) + dy4 * ty1 * (rsd[i + 1][j - 1][k][3] - 2.0 * rsd[i + 1][j][k][3] + rsd[i + 1][j + 1][k][3]);
                frct[i + 1][j][k][4] += ty3 * 0.1 * (flux[i + 1][j + 1][k][4] - flux[i + 1][j][k][4]) + dy5 * ty1 * (rsd[i + 1][j - 1][k][4] - 2.0 * rsd[i + 1][j][k][4] + rsd[i + 1][j + 1][k][4]);
            }
        }
        for (m = 0; m < 5; m++) {
            frct[i][1][k][m] -= dsspm * (5.0 * rsd[i][1][k][m] - 4.0 * rsd[i][2][k][m] + rsd[i][3][k][m]);
            frct[i][2][k][m] -= dsspm * (-4.0 * rsd[i][1][k][m] + 6.0 * rsd[i][2][k][m] - 4.0 * rsd[i][3][k][m] + rsd[i][4][k][m]);
            frct[i][ny - 3][k][m] -= dsspm * (rsd[i][ny - 5][k][m] - 4.0 * rsd[i][ny - 4][k][m] + 6.0 * rsd[i][ny - 3][k][m] - 4.0 * rsd[i][ny - 2][k][m]);
            frct[i][ny - 2][k][m] -= dsspm * (rsd[i][ny - 4][k][m] - 4.0 * rsd[i][ny - 3][k][m] + 5.0 * rsd[i][ny - 2][k][m]);

            if (i + 1 <= iend) {
                frct[i + 1][1][k][m] -= dsspm * (5.0 * rsd[i + 1][1][k][m] - 4.0 * rsd[i + 1][2][k][m] + rsd[i + 1][3][k][m]);
                frct[i + 1][2][k][m] -= dsspm * (-4.0 * rsd[i + 1][1][k][m] + 6.0 * rsd[i + 1][2][k][m] - 4.0 * rsd[i + 1][3][k][m] + rsd[i + 1][4][k][m]);
                frct[i + 1][ny - 3][k][m] -= dsspm * (rsd[i + 1][ny - 5][k][m] - 4.0 * rsd[i + 1][ny - 4][k][m] + 6.0 * rsd[i + 1][ny - 3][k][m] - 4.0 * rsd[i + 1][ny - 2][k][m]);
                frct[i + 1][ny - 2][k][m] -= dsspm * (rsd[i + 1][ny - 4][k][m] - 4.0 * rsd[i + 1][ny - 3][k][m] + 5.0 * rsd[i + 1][ny - 2][k][m]);
            }
        }
        jst1 = 3;
        jend1 = ny - 4;
        for (j = jst1; j <= jend1; j++) {
            for (m = 0; m < 5; m++) {
                double stencil = rsd[i][j - 2][k][m] - 4.0 * rsd[i][j - 1][k][m] + 6.0 * rsd[i][j][k][m] - 4.0 * rsd[i][j + 1][k][m] + rsd[i][j + 2][k][m];
                frct[i][j][k][m] -= dsspm * stencil;

                if (i + 1 <= iend) {
                    double stencil_next = rsd[i + 1][j - 2][k][m] - 4.0 * rsd[i + 1][j - 1][k][m] + 6.0 * rsd[i + 1][j][k][m] - 4.0 * rsd[i + 1][j + 1][k][m] + rsd[i + 1][j + 2][k][m];
                    frct[i + 1][j][k][m] -= dsspm * stencil_next;
                }
            }
        }
    }
}
}
