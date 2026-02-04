#include <stdio.h>

extern  int nx;
extern  int ny;
extern  int nz;
extern  int nx0;
extern  int ny0;
extern  double rsd[64][65][65][5];
extern  double ce[5][13];
extern int i;
extern int j;
extern int k;
extern int m;
extern int iglob;
extern int jglob;
extern double xi;
extern double eta;
extern double zeta;



void loop(){
for (i = 0; i < nx; i++) {
    iglob = i;
    xi = ((double)(iglob)) / (nx0 - 1);
    for (j = 0; j < ny; j++) {
        jglob = j;
        eta = ((double)(jglob)) / (ny0 - 1);
        for (k = 0; k < nz; k++) {
            zeta = ((double)(k)) / (nz - 1);
            rsd[i][j][k][0] = ce[0][0] + ce[0][1] * xi + ce[0][2] * eta + ce[0][3] * zeta + ce[0][4] * xi * xi + ce[0][5] * eta * eta + ce[0][6] * zeta * zeta + ce[0][7] * xi * xi * xi + ce[0][8] * eta * eta * eta + ce[0][9] * zeta * zeta * zeta + ce[0][10] * xi * xi * xi * xi + ce[0][11] * eta * eta * eta * eta + ce[0][12] * zeta * zeta * zeta * zeta;
            rsd[i][j][k][1] = ce[1][0] + ce[1][1] * xi + ce[1][2] * eta + ce[1][3] * zeta + ce[1][4] * xi * xi + ce[1][5] * eta * eta + ce[1][6] * zeta * zeta + ce[1][7] * xi * xi * xi + ce[1][8] * eta * eta * eta + ce[1][9] * zeta * zeta * zeta + ce[1][10] * xi * xi * xi * xi + ce[1][11] * eta * eta * eta * eta + ce[1][12] * zeta * zeta * zeta * zeta;
            rsd[i][j][k][2] = ce[2][0] + ce[2][1] * xi + ce[2][2] * eta + ce[2][3] * zeta + ce[2][4] * xi * xi + ce[2][5] * eta * eta + ce[2][6] * zeta * zeta + ce[2][7] * xi * xi * xi + ce[2][8] * eta * eta * eta + ce[2][9] * zeta * zeta * zeta + ce[2][10] * xi * xi * xi * xi + ce[2][11] * eta * eta * eta * eta + ce[2][12] * zeta * zeta * zeta * zeta;
            rsd[i][j][k][3] = ce[3][0] + ce[3][1] * xi + ce[3][2] * eta + ce[3][3] * zeta + ce[3][4] * xi * xi + ce[3][5] * eta * eta + ce[3][6] * zeta * zeta + ce[3][7] * xi * xi * xi + ce[3][8] * eta * eta * eta + ce[3][9] * zeta * zeta * zeta + ce[3][10] * xi * xi * xi * xi + ce[3][11] * eta * eta * eta * eta + ce[3][12] * zeta * zeta * zeta * zeta;
            rsd[i][j][k][4] = ce[4][0] + ce[4][1] * xi + ce[4][2] * eta + ce[4][3] * zeta + ce[4][4] * xi * xi + ce[4][5] * eta * eta + ce[4][6] * zeta * zeta + ce[4][7] * xi * xi * xi + ce[4][8] * eta * eta * eta + ce[4][9] * zeta * zeta * zeta + ce[4][10] * xi * xi * xi * xi + ce[4][11] * eta * eta * eta * eta + ce[4][12] * zeta * zeta * zeta * zeta;
        }
    }
}
}
