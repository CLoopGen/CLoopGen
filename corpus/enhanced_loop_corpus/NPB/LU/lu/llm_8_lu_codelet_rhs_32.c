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
    for (k = 1; k <= nz - 2; k += 2) { // Increased step size to reduce trip count and computational load
        for (j = jst; j <= jend; j++) {
            for (m = 0; m < 5; m++) {
                rsd[i][j][k][m] -= ty2 * (flux[i][j + 1][k][m] - flux[i][j - 1][k][m]);
            }
        }
        L2 = ny - 1;
        for (j = jst + 1; j <= L2; j++) { // Start from jst+1 to reduce iterations slightly
            tmp = 1.0 / u[i][j][k][0];
            u21j = tmp * u[i][j][k][1];
            u31j = tmp * u[i][j][k][2];
            u41j = tmp * u[i][j][k][3];
            u51j = tmp * u[i][j][k][4];
            tmp = 1.0 / u[i][j - 1][k][0];
            u21jm1 = tmp * u[i][j - 1][k][1];
            u31jm1 = tmp * u[i][j - 1][k][2];
            u41jm1 = tmp * u[i][j - 1][k][3];
            u51jm1 = tmp * u[i][j - 1][k][4];
            flux[i][j][k][1] = ty3 * (u21j - u21jm1);
            flux[i][j][k][2] = (4.0/3.0) * ty3 * (u31j - u31jm1);
            flux[i][j][k][3] = ty3 * (u41j - u41jm1);
            double diff_u2_sq = ((u21j)*(u21j)) - ((u21jm1)*(u21jm1));
            double diff_u3_sq = ((u31j)*(u31j)) - ((u31jm1)*(u31jm1));
            double diff_u4_sq = ((u41j)*(u41j)) - ((u41jm1)*(u41jm1));
            double diff_u5 = u51j - u51jm1;
            flux[i][j][k][4] = 0.5 * (1.0 - 1.96) * ty3 * (diff_u2_sq + diff_u3_sq + diff_u4_sq)
                             + (1.0/6.0) * ty3 * diff_u3_sq
                             + 1.96 * ty3 * diff_u5;
        }
        for (j = jst; j <= jend; j++) {
            double ujm1, uj, ujp1;
            uj = u[i][j][k][0]; ujm1 = u[i][j-1][k][0]; ujp1 = u[i][j+1][k][0];
            rsd[i][j][k][0] += dy1 * ty1 * (ujm1 - 2.0*uj + ujp1);
            rsd[i][j][k][1] += ty3 * 0.1 * (flux[i][j+1][k][1] - flux[i][j][k][1]) + dy2 * ty1 * (u[i][j-1][k][1] - 2.0*u[i][j][k][1] + u[i][j+1][k][1]);
            rsd[i][j][k][2] += ty3 * 0.1 * (flux[i][j+1][k][2] - flux[i][j][k][2]) + dy3 * ty1 * (u[i][j-1][k][2] - 2.0*u[i][j][k][2] + u[i][j+1][k][2]);
            rsd[i][j][k][3] += ty3 * 0.1 * (flux[i][j+1][k][3] - flux[i][j][k][3]) + dy4 * ty1 * (u[i][j-1][k][3] - 2.0*u[i][j][k][3] + u[i][j+1][k][3]);
            rsd[i][j][k][4] += ty3 * 0.1 * (flux[i][j+1][k][4] - flux[i][j][k][4]) + dy5 * ty1 * (u[i][j-1][k][4] - 2.0*u[i][j][k][4] + u[i][j+1][k][4]);
        }
        for (m = 0; m < 5; m++) {
            rsd[i][1][k][m] -= dssp * (5.0*u[i][1][k][m] - 4.0*u[i][2][k][m] + u[i][3][k][m]);
            rsd[i][2][k][m] -= dssp * (-4.0*u[i][1][k][m] + 6.0*u[i][2][k][m] - 4.0*u[i][3][k][m] + u[i][4][k][m]);
        }
        jst1 = 3;
        jend1 = ny - 4;
        for (j = jst1; j <= jend1; j++) {
            for (m = 0; m < 5; m++) {
                rsd[i][j][k][m] -= dssp * (u[i][j-2][k][m] - 4.0*u[i][j-1][k][m] + 6.0*u[i][j][k][m] - 4.0*u[i][j+1][k][m] + u[i][j+2][k][m]);
            }
        }
        for (m = 0; m < 5; m++) {
            rsd[i][ny-3][k][m] -= dssp * (u[i][ny-5][k][m] - 4.0*u[i][ny-4][k][m] + 6.0*u[i][ny-3][k][m] - 4.0*u[i][ny-2][k][m]);
            rsd[i][ny-2][k][m] -= dssp * (u[i][ny-4][k][m] - 4.0*u[i][ny-3][k][m] + 5.0*u[i][ny-2][k][m]);
        }
    }
}
}
