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
            for (m = 0; m < 5; m++) {
                double term1 = ce[m][0] + ce[m][1] * xi + ce[m][2] * eta + ce[m][3] * zeta;
                double term2 = ce[m][4] * xi * xi + ce[m][5] * eta * eta + ce[m][6] * zeta * zeta;
                double term3 = ce[m][7] * xi * xi * xi + ce[m][8] * eta * eta * eta + ce[m][9] * zeta * zeta * zeta;
                double term4 = ce[m][10] * xi * xi * xi * xi + ce[m][11] * eta * eta * eta * eta + ce[m][12] * zeta * zeta * zeta * zeta;

                if (i + j + k < nx/2 + ny/2 + nz/2) {
                    rsd[i][j][k][m] = term1 + term2;
                } else {
                    rsd[i][j][k][m] = term1 + term2 + term3 + term4;
                }
            }
        }
    }
}
}
