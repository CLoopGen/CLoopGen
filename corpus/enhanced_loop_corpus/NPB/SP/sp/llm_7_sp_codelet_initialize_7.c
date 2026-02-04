#include <stdio.h>

extern  double u[5][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
    for (i = 0; i <= 64 - 1; i++) {
        for (j = 0; j <= 64 - 1; j++) {
            for (k = 0; k <= 64 - 1; k++) {
                // Introduce WAW and WAR by reordering and overwriting with loop-carried dependency
                u[4][i][j][k] = u[4][i][j][k] + 1.; // Loop-carried dependence if previous iterations affect this
                u[3][i][j][k] = u[4][i][j][k] * 0.5;
                u[2][i][j][k] = u[3][i][j][k] * 0.5;
                u[1][i][j][k] = u[2][i][j][k] * 0.5;
                u[0][i][j][k] = u[1][i][j][k] * 0.5;

                // Final assignment creates WAW with initial value, WAR across statements
                u[0][i][j][k] = 1.;
                u[1][i][j][k] = 0.;
                u[2][i][j][k] = 0.;
                u[3][i][j][k] = 0.;
                u[4][i][j][k] = 1.;
            }
        }
    }
}
