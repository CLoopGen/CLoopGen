#include <stdio.h>

extern  int nx;
extern  int ny;
extern  int nz;
extern  double frct[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (i = 0; i < nx; i++) {
    for (j = 0; j < ny; j++) {
        for (k = 0; k < nz; k++) {
            frct[i][j][k][0] = 0.;
            frct[i][j][k][1] = 0.;
            frct[i][j][k][2] = 0.;
            frct[i][j][k][3] = 0.;
            frct[i][j][k][4] = 0.;
        }
    }
}
}
