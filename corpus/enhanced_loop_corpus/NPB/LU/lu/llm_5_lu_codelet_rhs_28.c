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
    for (i = 0; i < nx; i++) {
        for (j = 0; j < ny; j++) {
            for (k = 0; k < nz; k++) {
                for (m = 0; m < 5; m++) {
                    if (frct[i][j][k][m] > -1e-10 && frct[i][j][k][m] < 1e-10) {
                        rsd[i][j][k][m] = 0.0;
                    } else {
                        rsd[i][j][k][m] = -frct[i][j][k][m];
                    }
                }
            }
        }
    }
}
