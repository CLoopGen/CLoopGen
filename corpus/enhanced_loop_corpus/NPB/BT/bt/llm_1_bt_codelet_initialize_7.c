#include <stdio.h>

extern  double u[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (i = 0; i < 64; i++) {
    for (j = 0; j < 64; j++) {
        u[i][j][0][0] = 1.;
        u[i][j][0][1] = 1.;
        u[i][j][0][2] = 1.;
        u[i][j][0][3] = 1.;
        u[i][j][0][4] = 1.;
        for (k = 1; k < 64; k++) {
            for (m = 0; m < 5; m++) {
                u[i][j][k][m] = 1.;
            }
        }
    }
}
}
