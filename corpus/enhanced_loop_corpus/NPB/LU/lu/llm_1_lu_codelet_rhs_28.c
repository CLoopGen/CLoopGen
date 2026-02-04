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
for (i = 0; i <= nx - 1; i++) {
    for (j = 0; j <= ny - 1; j++) {
        for (k = 0; k <= nz - 1; k++) {
            rsd[i][j][k][0] = -frct[i][j][k][0];
            rsd[i][j][k][1] = -frct[i][j][k][1];
            rsd[i][j][k][2] = -frct[i][j][k][2];
            rsd[i][j][k][3] = -frct[i][j][k][3];
            rsd[i][j][k][4] = -frct[i][j][k][4];
        }
    }
}
}
