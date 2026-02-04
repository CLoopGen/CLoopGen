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
int stride = 2;
for (i = 0; i < nx; i += stride) {
    iglob = i;
    xi = ((double)(iglob)) / (nx0 - 1);
    double xi2 = xi * xi;
    double xi3 = xi2 * xi;
    double xi4 = xi3 * xi;
    for (j = 0; j < ny; j += stride) {
        jglob = j;
        eta = ((double)(jglob)) / (ny0 - 1);
        double eta2 = eta * eta;
        double eta3 = eta2 * eta;
        double eta4 = eta3 * eta;
        for (k = 0; k < nz; k += stride) {
            zeta = ((double)(k)) / (nz - 1);
            double zeta2 = zeta * zeta;
            double zeta3 = zeta2 * zeta;
            double zeta4 = zeta3 * zeta;
            for (m = 0; m < 5; m++) {
                rsd[i][j][k][m] = ce[m][0] 
                                + ce[m][1] * xi 
                                + ce[m][2] * eta 
                                + ce[m][3] * zeta 
                                + ce[m][4] * xi2 
                                + ce[m][5] * eta2 
                                + ce[m][6] * zeta2 
                                + ce[m][7] * xi3 
                                + ce[m][8] * eta3 
                                + ce[m][9] * zeta3 
                                + ce[m][10] * xi4 
                                + ce[m][11] * eta4 
                                + ce[m][12] * zeta4;
            }
        }
    }
}
}
