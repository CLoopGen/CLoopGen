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
        for (k = 1; k <= grid_points[2] - 2; k += 2) { // Increased stride to reduce trip count and computational intensity
            if (k + 1 > grid_points[2] - 2) continue; // Ensure we don't exceed bounds when processing two points

            // Process k and k+1 together to maintain some data reuse
            double xvel1 = us[i][j][k];
            double yvel1 = vs[i][j][k];
            double zvel1 = ws[i][j][k];
            double ac1 = speed[i][j][k];
            double acinv1 = ainv[i][j][k];
            double ac2u1 = ac1 * ac1;
            double r1_1 = rhs[0][i][j][k];
            double r2_1 = rhs[1][i][j][k];
            double r3_1 = rhs[2][i][j][k];
            double r4_1 = rhs[3][i][j][k];
            double r5_1 = rhs[4][i][j][k];
            double uzik1_1 = u[0][i][j][k];
            double btuz1 = bt * uzik1_1;
            double t1_1 = btuz1 * acinv1 * (r4_1 + r5_1);
            double t2_1 = r3_1 + t1_1;
            double t3_1 = btuz1 * (r4_1 - r5_1);

            rhs[0][i][j][k] = t2_1;
            rhs[1][i][j][k] = -uzik1_1 * r2_1 + xvel1 * t2_1;
            rhs[2][i][j][k] = uzik1_1 * r1_1 + yvel1 * t2_1;
            rhs[3][i][j][k] = zvel1 * t2_1 + t3_1;
            rhs[4][i][j][k] = uzik1_1 * (-xvel1 * r2_1 + yvel1 * r1_1) + qs[i][j][k] * t2_1 + c2iv * ac2u1 * t1_1 + zvel1 * t3_1;

            // Second point in the pair: k+1
            double xvel2 = us[i][j][k+1];
            double yvel2 = vs[i][j][k+1];
            double zvel2 = ws[i][j][k+1];
            double ac2 = speed[i][j][k+1];
            double acinv2 = ainv[i][j][k+1];
            double ac2u2 = ac2 * ac2;
            double r1_2 = rhs[0][i][j][k+1];
            double r2_2 = rhs[1][i][j][k+1];
            double r3_2 = rhs[2][i][j][k+1];
            double r4_2 = rhs[3][i][j][k+1];
            double r5_2 = rhs[4][i][j][k+1];
            double uzik1_2 = u[0][i][j][k+1];
            double btuz2 = bt * uzik1_2;
            double t1_2 = btuz2 * acinv2 * (r4_2 + r5_2);
            double t2_2 = r3_2 + t1_2;
            double t3_2 = btuz2 * (r4_2 - r5_2);

            rhs[0][i][j][k+1] = t2_2;
            rhs[1][i][j][k+1] = -uzik1_2 * r2_2 + xvel2 * t2_2;
            rhs[2][i][j][k+1] = uzik1_2 * r1_2 + yvel2 * t2_2;
            rhs[3][i][j][k+1] = zvel2 * t2_2 + t3_2;
            rhs[4][i][j][k+1] = uzik1_2 * (-xvel2 * r2_2 + yvel2 * r1_2) + qs[i][j][k+1] * t2_2 + c2iv * ac2u2 * t1_2 + zvel2 * t3_2;
        }
    }
}
}
