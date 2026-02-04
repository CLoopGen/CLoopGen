#include <stdio.h>

extern  double u[5][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 0; i <= 64 - 1; i++) {
    for (j = 0; j <= 64 - 1; j++) {
        for (k = 0; k <= 64 - 1; k++) {
            if ((i + j + k) % 2 == 0) {
                u[0][i][j][k] = 1.;
                u[1][i][j][k] = 0.;
            } else {
                u[2][i][j][k] = 0.;
                u[3][i][j][k] = 0.;
            }
            u[4][i][j][k] = 1.;
        }
    }
}
}
