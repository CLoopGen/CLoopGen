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
extern  double dssp;
extern  double u[64][65][65][5];
extern  double rsd[64][65][65][5];
extern  double flux[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;
extern int L2;
extern int jst1;
extern int jend1;
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
        // Eliminate loop-carried dependency by fusing flux computation earlier
        L2 = ny - 1;
        for (j = jst; j <= L2; j++) {
            tmp = 1. / u[i][j][k][0];
            u21j = tmp * u[i][j][k][1];
            u31j = tmp * u[i][j][k][2];
            u41j = tmp * u[i][j][k][3];
            u51j = tmp * u[i][j][k][4];
            tmp = 1. / u[i][j - 1][k][0];
            u21jm1 = tmp * u[i][j - 1][k][1];
            u31jm1 = tmp * u[i][j - 1][k][2];
            u41jm1 = tmp * u[i][j - 1][k][3];
            u51jm1 = tmp * u[i][j - 1][k][4];
            flux[i][j][k][1] = ty3 * (u21j - u21jm1);
            flux[i][j][k][2] = (4. / 3.) * ty3 * (u31j - u31jm1);
            flux[i][j][k][3] = ty3 * (u41j - u41jm1);
            flux[i][j][k][4] = 0.5 * (1. - 1.3999999999999999 * 1.3999999999999999) * ty3 * ((((u21j) * (u21j)) + ((u31j) * (u31j)) + ((u41j) * (u41j))) - (((u21jm1) * (u21jm1)) + ((u31jm1) * (u31jm1)) + ((u41jm1) * (u41jm1)))) + (1. / 6.) * ty3 * (((u31j) * (u31j)) - ((u31jm1) * (u31jm1))) + 1.3999999999999999 * 1.3999999999999999 * ty3 * (u51j - u51jm1);
        }
        // Introduce artificial loop-independent accumulation via temporary array to break WAW on rsd
        double rsd_temp[65][5] = {0}; // Local accumulation buffer for j-dimension
        for (j = jst; j <= jend; j++) {
            for (m = 0; m < 5; m++) {
                rsd_temp[j][m] = rsd[i][j][k][m] - ty2 * (flux[i][j + 1][k][m] - flux[i][j - 1][k][m]);
            }
        }
        // Second pass: apply diffusion and update using local buffer to remove intra-loop write conflicts
        for (j = jst; j <= jend; j++) {
            rsd_temp[j][0] += dy1 * ty1 * (u[i][j - 1][k][0] - 2. * u[i][j][k][0] + u[i][j + 1][k][0]);
            rsd_temp[j][1] += ty3 * 0.10000000000000001 * 1. * (flux[i][j + 1][k][1] - flux[i][j][k][1]) + dy2 * ty1 * (u[i][j - 1][k][1] - 2. * u[i][j][k][1] + u[i][j + 1][k][1]);
            rsd_temp[j][2] += ty3 * 0.10000000000000001 * 1. * (flux[i][j + 1][k][2] - flux[i][j][k][2]) + dy3 * ty1 * (u[i][j - 1][k][2] - 2. * u[i][j][k][2] + u[i][j + 1][k][2]);
            rsd_temp[j][3] += ty3 * 0.10000000000000001 * 1. * (flux[i][j + 1][k][3] - flux[i][j][k][3]) + dy4 * ty1 * (u[i][j - 1][k][3] - 2. * u[i][j][k][3] + u[i][j + 1][k][3]);
            rsd_temp[j][4] += ty3 * 0.10000000000000001 * 1. * (flux[i][j + 1][k][4] - flux[i][j][k][4]) + dy5 * ty1 * (u[i][j - 1][k][4] - 2. * u[i][j][k][4] + u[i][j + 1][k][4]);
        }
        // Apply dssp smoothing with reduced loop iterations via direct assignment to avoid repeated indexing
        for (m = 0; m < 5; m++) {
            rsd_temp[1][m] -= dssp * (+5. * u[i][1][k][m] - 4. * u[i][2][k][m] + u[i][3][k][m]);
            rsd_temp[2][m] -= dssp * (-4. * u[i][1][k][m] + 6. * u[i][2][k][m] - 4. * u[i][3][k][m] + u[i][4][k][m]);
            rsd_temp[ny - 3][m] -= dssp * (u[i][ny - 5][k][m] - 4. * u[i][ny - 4][k][m] + 6. * u[i][ny - 3][k][m] - 4. * u[i][ny - 2][k][m]);
            rsd_temp[ny - 2][m] -= dssp * (u[i][ny - 4][k][m] - 4. * u[i][ny - 3][k][m] + 5. * u[i][ny - 2][k][m]);
        }
        jst1 = 3;
        jend1 = ny - 4;
        for (j = jst1; j <= jend1; j++) {
            for (m = 0; m < 5; m++) {
                rsd_temp[j][m] -= dssp * (u[i][j - 2][k][m] - 4. * u[i][j - 1][k][m] + 6. * u[i][j][k][m] - 4. * u[i][j + 1][k][m] + u[i][j + 2][k][m]);
            }
        }
        // Final write-back to rsd to eliminate intermediate WAW hazards
        for (j = jst; j <= jend; j++) {
            for (m = 0; m < 5; m++) {
                rsd[i][j][k][m] = rsd_temp[j][m];
            }
        }
    }
}
}
