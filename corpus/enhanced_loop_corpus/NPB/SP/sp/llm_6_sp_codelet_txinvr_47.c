#include <stdio.h>

extern  int grid_points[3];
extern  double c2;
extern  double bt;
extern  double us[65][65][65];
extern  double vs[65][65][65];
extern  double ws[65][65][65];
extern  double qs[65][65][65];
extern  double ainv[65][65][65];
extern  double rho_i[65][65][65];
extern  double speed[65][65][65];
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern double t1;
extern double t2;
extern double t3;
extern double ac;
extern double ru1;
extern double uu;
extern double vv;
extern double ww;
extern double r1;
extern double r2;
extern double r3;
extern double r4;
extern double r5;
extern double ac2inv;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            double temp_ru1 = rho_i[i][j][k];
            double temp_uu = us[i][j][k];
            double temp_vv = vs[i][j][k];
            double temp_ww = ws[i][j][k];
            double temp_ac = speed[i][j][k];
            double temp_ac2inv = ainv[i][j][k] * ainv[i][j][k];
            double temp_r1 = rhs[0][i][j][k];
            double temp_r2 = rhs[1][i][j][k];
            double temp_r3 = rhs[2][i][j][k];
            double temp_r4 = rhs[3][i][j][k];
            double temp_r5 = rhs[4][i][j][k];

            double temp_t1 = c2 * temp_ac2inv * (qs[i][j][k] * temp_r1 - temp_uu * temp_r2 - temp_vv * temp_r3 - temp_ww * temp_r4 + temp_r5);
            double temp_t2 = bt * temp_ru1 * (temp_uu * temp_r1 - temp_r2);
            double temp_t3 = (bt * temp_ru1 * temp_ac) * temp_t1;

            rhs[0][i][j][k] = temp_r1 - temp_t1;
            rhs[1][i][j][k] = -temp_ru1 * (temp_ww * temp_r1 - temp_r4);
            rhs[2][i][j][k] = temp_ru1 * (temp_vv * temp_r1 - temp_r3);
            rhs[3][i][j][k] = -temp_t2 + temp_t3;
            rhs[4][i][j][k] = temp_t2 + temp_t3;
        }
    }
}
}
