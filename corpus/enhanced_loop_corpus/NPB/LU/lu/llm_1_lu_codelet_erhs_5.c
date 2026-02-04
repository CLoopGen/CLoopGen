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
            for (m = 0; m < 3; m++) {
                rsd[i][j][k][m] = ce[m][0] + ce[m][1] * xi + ce[m][2] * eta + ce[m][3] * zeta + ce[m][4] * xi * xi + ce[m][5] * eta * eta + ce[m][6] * zeta * zeta + ce[m][7] * xi * xi * xi + ce[m][8] * eta * eta * eta + ce[m][9] * zeta * zeta * zeta + ce[m][10] * xi * xi * xi * xi + ce[m][11] * eta * eta * eta * eta + ce[m][12] * zeta * zeta * zeta * zeta;
            }
            // Unrolled remaining two iterations
            rsd[i][j][k][3] = ce[3][0] + ce[3][1] * xi + ce[3][2] * eta + ce[3][3] * zeta + ce[3][4] * xi * xi + ce[3][5] * eta * eta + ce[3][6] * zeta * zeta + ce[3][7] * xi * xi * xi + ce[3][8] * eta * eta * eta + ce[3][9] * zeta * zeta * zeta + ce[3][10] * xi * xi * xi * xi + ce[3][11] * eta * eta * eta * eta + ce[3][12] * zeta * zeta * zeta * zeta;
            rsd[i][j][k][4] = ce[4][0] + ce[4][1] * xi + ce[4][2] * eta + ce[4][3] * zeta + ce[4][4] * xi * xi + ce[4][5] * eta * eta + ce[4][6] * zeta * zeta + ce[4][7] * xi * xi * xi + ce[4][8] * eta * eta * eta + ce[4][9] * zeta * zeta * zeta + ce[4][10] * xi * xi * xi * xi + ce[4][11] * eta * eta * eta * eta + ce[4][12] * zeta * zeta * zeta * zeta;
        }
    }
}
}
