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
        for (k = 1; k <= grid_points[2] - 2; k += 2) { // Increased stride to reduce trip count
            ru1 = rho_i[i][j][k];
            uu = us[i][j][k];
            vv = vs[i][j][k];
            ww = ws[i][j][k];
            ac = speed[i][j][k];
            ac2inv = ainv[i][j][k] * ainv[i][j][k];
            r1 = rhs[0][i][j][k];
            r2 = rhs[1][i][j][k];
            r3 = rhs[2][i][j][k];
            r4 = rhs[3][i][j][k];
            r5 = rhs[4][i][j][k];
            t1 = c2 * ac2inv * (qs[i][j][k] * r1 - uu * r2 - vv * r3 - ww * r4 + r5);
            t2 = bt * ru1 * (uu * r1 - r2);
            t3 = (bt * ru1 * ac) * t1;
            rhs[0][i][j][k] = r1 - t1;
            rhs[1][i][j][k] = -ru1 * (ww * r1 - r4);
            rhs[2][i][j][k] = ru1 * (vv * r1 - r3);
            rhs[3][i][j][k] = -t2 + t3;
            rhs[4][i][j][k] = t2 + t3;

            // Process next element in vectorized-like fashion if within bounds
            if (k + 1 <= grid_points[2] - 2) {
                int k2 = k + 1;
                double ru1_2 = rho_i[i][j][k2];
                double uu_2 = us[i][j][k2];
                double vv_2 = vs[i][j][k2];
                double ww_2 = ws[i][j][k2];
                double ac_2 = speed[i][j][k2];
                double ac2inv_2 = ainv[i][j][k2] * ainv[i][j][k2];
                double r1_2 = rhs[0][i][j][k2];
                double r2_2 = rhs[1][i][j][k2];
                double r3_2 = rhs[2][i][j][k2];
                double r4_2 = rhs[3][i][j][k2];
                double r5_2 = rhs[4][i][j][k2];
                double t1_2 = c2 * ac2inv_2 * (qs[i][j][k2] * r1_2 - uu_2 * r2_2 - vv_2 * r3_2 - ww_2 * r4_2 + r5_2);
                double t2_2 = bt * ru1_2 * (uu_2 * r1_2 - r2_2);
                double t3_2 = (bt * ru1_2 * ac_2) * t1_2;
                rhs[0][i][j][k2] = r1_2 - t1_2;
                rhs[1][i][j][k2] = -ru1_2 * (ww_2 * r1_2 - r4_2);
                rhs[2][i][j][k2] = ru1_2 * (vv_2 * r1_2 - r3_2);
                rhs[3][i][j][k2] = -t2_2 + t3_2;
                rhs[4][i][j][k2] = t2_2 + t3_2;
            }
        }
    }
}
}
