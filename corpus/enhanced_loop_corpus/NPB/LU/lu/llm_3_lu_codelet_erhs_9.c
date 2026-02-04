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
        // Modify memory access to use indirect indexing via pointer arithmetic for better locality
        double (*frct_ptr)[65][65][5] = &frct[i];
        double (*flux_ptr)[65][65][5] = &flux[i];
        double (*rsd_ptr)[65][65][5] = &rsd[i];

        for (j = jst; j <= jend; j++) {
            for (m = 0; m < 5; m++) {
                (*frct_ptr)[j][k][m] -= ty2 * ((*flux_ptr)[j + 1][k][m] - (*flux_ptr)[j - 1][k][m]);
            }
        }

        for (j = jst; j <= L2; j++) {
            tmp = 1. / (*rsd_ptr)[j][k][0];
            u21j = tmp * (*rsd_ptr)[j][k][1];
            u31j = tmp * (*rsd_ptr)[j][k][2];
            u41j = tmp * (*rsd_ptr)[j][k][3];
            u51j = tmp * (*rsd_ptr)[j][k][4];
            tmp = 1. / (*rsd_ptr)[j - 1][k][0];
            u21jm1 = tmp * (*rsd_ptr)[j - 1][k][1];
            u31jm1 = tmp * (*rsd_ptr)[j - 1][k][2];
            u41jm1 = tmp * (*rsd_ptr)[j - 1][k][3];
            u51jm1 = tmp * (*rsd_ptr)[j - 1][k][4];
            (*flux_ptr)[j][k][1] = ty3 * (u21j - u21jm1);
            (*flux_ptr)[j][k][2] = (4. / 3.) * ty3 * (u31j - u31jm1);
            (*flux_ptr)[j][k][3] = ty3 * (u41j - u41jm1);
            (*flux_ptr)[j][k][4] = 0.5 * (1. - 1.3999999999999999 * 1.3999999999999999) * ty3 * ((u21j * u21j + u31j * u31j + u41j * u41j) - (u21jm1 * u21jm1 + u31jm1 * u31jm1 + u41jm1 * u41jm1)) + (1. / 6.) * ty3 * (u31j * u31j - u31jm1 * u31jm1) + 1.3999999999999999 * 1.3999999999999999 * ty3 * (u51j - u51jm1);
        }

        for (j = jst; j <= jend; j++) {
            (*frct_ptr)[j][k][0] += dy1 * ty1 * ((*rsd_ptr)[j - 1][k][0] - 2. * (*rsd_ptr)[j][k][0] + (*rsd_ptr)[j + 1][k][0]);
            (*frct_ptr)[j][k][1] += ty3 * 0.10000000000000001 * 1. * ((*flux_ptr)[j + 1][k][1] - (*flux_ptr)[j][k][1]) + dy2 * ty1 * ((*rsd_ptr)[j - 1][k][1] - 2. * (*rsd_ptr)[j][k][1] + (*rsd_ptr)[j + 1][k][1]);
            (*frct_ptr)[j][k][2] += ty3 * 0.10000000000000001 * 1. * ((*flux_ptr)[j + 1][k][2] - (*flux_ptr)[j][k][2]) + dy3 * ty1 * ((*rsd_ptr)[j - 1][k][2] - 2. * (*rsd_ptr)[j][k][2] + (*rsd_ptr)[j + 1][k][2]);
            (*frct_ptr)[j][k][3] += ty3 * 0.10000000000000001 * 1. * ((*flux_ptr)[j + 1][k][3] - (*flux_ptr)[j][k][3]) + dy4 * ty1 * ((*rsd_ptr)[j - 1][k][3] - 2. * (*rsd_ptr)[j][k][3] + (*rsd_ptr)[j + 1][k][3]);
            (*frct_ptr)[j][k][4] += ty3 * 0.10000000000000001 * 1. * ((*flux_ptr)[j + 1][k][4] - (*flux_ptr)[j][k][4]) + dy5 * ty1 * ((*rsd_ptr)[j - 1][k][4] - 2. * (*rsd_ptr)[j][k][4] + (*rsd_ptr)[j + 1][k][4]);
        }

        for (m = 0; m < 5; m++) {
            (*frct_ptr)[1][k][m] -= dsspm * (+5. * (*rsd_ptr)[1][k][m] - 4. * (*rsd_ptr)[2][k][m] + (*rsd_ptr)[3][k][m]);
            (*frct_ptr)[2][k][m] -= dsspm * (-4. * (*rsd_ptr)[1][k][m] + 6. * (*rsd_ptr)[2][k][m] - 4. * (*rsd_ptr)[3][k][m] + (*rsd_ptr)[4][k][m]);
        }

        jst1 = 3;
        jend1 = ny - 4;
        for (j = jst1; j <= jend1; j++) {
            for (m = 0; m < 5; m++) {
                (*frct_ptr)[j][k][m] -= dsspm * ((*rsd_ptr)[j - 2][k][m] - 4. * (*rsd_ptr)[j - 1][k][m] + 6. * (*rsd_ptr)[j][k][m] - 4. * (*rsd_ptr)[j + 1][k][m] + (*rsd_ptr)[j + 2][k][m]);
            }
        }

        for (m = 0; m < 5; m++) {
            (*frct_ptr)[ny - 3][k][m] -= dsspm * ((*rsd_ptr)[ny - 5][k][m] - 4. * (*rsd_ptr)[ny - 4][k][m] + 6. * (*rsd_ptr)[ny - 3][k][m] - 4. * (*rsd_ptr)[ny - 2][k][m]);
            (*frct_ptr)[ny - 2][k][m] -= dsspm * ((*rsd_ptr)[ny - 4][k][m] - 4. * (*rsd_ptr)[ny - 3][k][m] + 5. * (*rsd_ptr)[ny - 2][k][m]);
        }
    }
}
}
