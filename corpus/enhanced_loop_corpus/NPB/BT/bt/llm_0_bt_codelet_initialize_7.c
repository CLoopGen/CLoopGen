#include <stdio.h>

extern  double u[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (i = 0; i < 64; i++) {
    for (j = 0; j < 64; j++) {
        for (k = 0; k < 64; k++) {
            u[i][j][k][0] = 1.;
            u[i][j][k][1] = 1.;
            u[i][j][k][2] = 1.;
            u[i][j][k][3] = 1.;
            u[i][j][k][4] = 1.;
        }
    }
}
}
