#include <stdio.h>

extern  int grid_points[3];
extern  double bt;
extern  double c2iv;
extern  double u[5][65][65][65];
extern  double us[65][65][65];
extern  double vs[65][65][65];
extern  double ws[65][65][65];
extern  double qs[65][65][65];
extern  double ainv[65][65][65];
extern  double speed[65][65][65];
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern double t1;
extern double t2;
extern double t3;
extern double ac;
extern double xvel;
extern double yvel;
extern double zvel;
extern double r1;
extern double r2;
extern double r3;
extern double r4;
extern double r5;
extern double btuz;
extern double acinv;
extern double ac2u;
extern double uzik1;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            double temp_us = us[i][j][k];
            double temp_vs = vs[i][j][k];
            double temp_ws = ws[i][j][k];
            double temp_ac = speed[i][j][k];
            double temp_acinv = ainv[i][j][k];
            double temp_ac2u = temp_ac * temp_ac;
            double temp_rhs[5];
            temp_rhs[0] = rhs[0][i][j][k];
            temp_rhs[1] = rhs[1][i][j][k];
            temp_rhs[2] = rhs[2][i][j][k];
            temp_rhs[3] = rhs[3][i][j][k];
            temp_rhs[4] = rhs[4][i][j][k];
            double uzik1 = u[0][i][j][k];
            double btuz = bt * uzik1;
            double t1 = btuz * temp_acinv * (temp_rhs[3] + temp_rhs[4]);
            double t2 = temp_rhs[2] + t1;
            double t3 = btuz * (temp_rhs[3] - temp_rhs[4]);

            rhs[0][i][j][k] = t2;
            rhs[1][i][j][k] = -uzik1 * temp_rhs[1] + temp_us * t2;
            rhs[2][i][j][k] = uzik1 * temp_rhs[0] + temp_vs * t2;
            rhs[3][i][j][k] = temp_ws * t2 + t3;
            rhs[4][i][j][k] = uzik1 * (-temp_us * temp_rhs[1] + temp_vs * temp_rhs[0]) + 
                              qs[i][j][k] * t2 + c2iv * temp_ac2u * t1 + temp_ws * t3;
        }
    }
}
}
