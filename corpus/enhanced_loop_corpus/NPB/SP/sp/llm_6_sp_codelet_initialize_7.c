#include <stdio.h>

extern  double u[5][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
    for (i = 0; i <= 64 - 1; i++) {
        for (j = 0; j <= 64 - 1; j++) {
            for (k = 0; k <= 64 - 1; k++) {
                u[0][i][j][k] = 1.;
                u[1][i][j][k] = u[0][i][j][k] + 1.; // RAW dependency: u[1] depends on u[0]
                u[2][i][j][k] = u[1][i][j][k] * 2.; // RAW dependency: u[2] depends on u[1]
                u[3][i][j][k] = u[2][i][j][k] - 1.; // RAW dependency: u[3] depends on u[2]
                u[4][i][j][k] = u[3][i][j][k];      // RAW dependency: u[4] depends on u[3]
            }
        }
    }
}
