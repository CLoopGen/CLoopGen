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
            double temp_r1 = rhs[0][i][j][k];
            double temp_r2 = rhs[1][i][j][k];
            double temp_r3 = rhs[2][i][j][k];
            double temp_r4 = rhs[3][i][j][k];
            double temp_r5 = rhs[4][i][j][k];

            double temp_t1 = bt * temp_r1;
            double temp_t2 = 0.5 * (temp_r4 + temp_r5);

            rhs[4][i][j][k] = temp_t1 + temp_t2;
            rhs[3][i][j][k] = -temp_t1 + temp_t2;
            rhs[2][i][j][k] = temp_r2;
            rhs[1][i][j][k] = -temp_r3;
            rhs[0][i][j][k] = bt * (temp_r4 - temp_r5);
        }
    }
}
}
