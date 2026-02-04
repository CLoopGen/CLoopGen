#include <stdio.h>

extern  int grid_points[3];
extern  double bt;
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern double r1;
extern double r2;
extern double r3;
extern double r4;
extern double r5;
extern double t1;
extern double t2;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            double temp_r[5];
            temp_r[0] = rhs[0][i][j][k];
            temp_r[1] = rhs[1][i][j][k];
            temp_r[2] = rhs[2][i][j][k];
            temp_r[3] = rhs[3][i][j][k];
            temp_r[4] = rhs[4][i][j][k];

            double t1_local = bt * temp_r[2];
            double t2_local = 0.5 * (temp_r[3] + temp_r[4]);

            rhs[0][i][j][k] = -temp_r[1];
            rhs[1][i][j][k] = temp_r[0];
            rhs[2][i][j][k] = bt * (temp_r[3] - temp_r[4]);
            rhs[3][i][j][k] = -t1_local + t2_local;
            rhs[4][i][j][k] = t1_local + t2_local;
        }
    }
}
}
