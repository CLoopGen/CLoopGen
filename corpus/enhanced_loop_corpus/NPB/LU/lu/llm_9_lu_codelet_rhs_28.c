#include <stdio.h>

extern  int nx;
extern  int ny;
extern  int nz;
extern  double rsd[64][65][65][5];
extern  double frct[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    for (i = 0; i <= nx - 1; i += 2) {
        for (j = 0; j <= ny - 1; j += 2) {
            for (k = 0; k <= nz - 1; k += 2) {
                for (m = 0; m < 5; m++) {
                    double temp1 = -frct[i][j][k][m];
                    double temp2 = (i > 0) ? -frct[i-1][j][k][m] : temp1;
                    double temp3 = (j > 0) ? -frct[i][j-1][k][m] : temp1;
                    double temp4 = (k > 0) ? -frct[i][j][k-1][m] : temp1;
                    rsd[i][j][k][m] = (temp1 + temp2 + temp3 + temp4) * 0.25;
                    if (i+1 < nx) rsd[i+1][j][k][m] = temp1;
                    if (j+1 < ny) rsd[i][j+1][k][m] = temp1;
                    if (k+1 < nz) rsd[i][j][k+1][m] = temp1;
                }
            }
        }
    }
}
