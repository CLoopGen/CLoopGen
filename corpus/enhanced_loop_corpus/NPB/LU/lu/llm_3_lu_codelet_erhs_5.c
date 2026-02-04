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
    int idx = 0;
    for (k = 0; k < nz; k++) {
        zeta = ((double)(k)) / (nz - 1);
        for (j = 0; j < ny; j++) {
            jglob = j;
            eta = ((double)(jglob)) / (ny0 - 1);
            for (i = 0; i < nx; i++) {
                iglob = i;
                xi = ((double)(iglob)) / (nx0 - 1);
                for (m = 0; m < 5; m++) {
                    double basis[13];
                    basis[0] = 1.0;
                    basis[1] = xi;
                    basis[2] = eta;
                    basis[3] = zeta;
                    basis[4] = xi * xi;
                    basis[5] = eta * eta;
                    basis[6] = zeta * zeta;
                    basis[7] = basis[4] * xi;
                    basis[8] = basis[5] * eta;
                    basis[9] = basis[6] * zeta;
                    basis[10] = basis[7] * xi;
                    basis[11] = basis[8] * eta;
                    basis[12] = basis[9] * zeta;

                    double sum = 0.0;
                    for (int c = 0; c < 13; c++) {
                        sum += ce[m][c] * basis[c];
                    }
                    rsd[i][j][k][m] = sum;
                }
            }
        }
    }
}
