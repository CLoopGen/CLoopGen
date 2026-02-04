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
for (k = 1; k <= grid_points[2] - 2; k++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (i = 1; i <= grid_points[0] - 2; i++) {
            xvel = us[i][j][k];
            yvel = vs[i][j][k];
            zvel = ws[i][j][k];
            ac = speed[i][j][k];
            acinv = ainv[i][j][k];
            ac2u = ac * ac;
            r1 = rhs[0][i][j][k];
            r2 = rhs[1][i][j][k];
            r3 = rhs[2][i][j][k];
            r4 = rhs[3][i][j][k];
            r5 = rhs[4][i][j][k];
            uzik1 = u[0][i][j][k];
            btuz = bt * uzik1;
            t1 = btuz * acinv * (r4 + r5);
            t2 = r3 + t1;
            t3 = btuz * (r4 - r5);
            rhs[0][i][j][k] = t2;
            rhs[1][i][j][k] = -uzik1 * r2 + xvel * t2;
            rhs[2][i][j][k] = uzik1 * r1 + yvel * t2;
            rhs[3][i][j][k] = zvel * t2 + t3;
            rhs[4][i][j][k] = uzik1 * (-xvel * r2 + yvel * r1) + qs[i][j][k] * t2 + c2iv * ac2u * t1 + zvel * t3;
        }
    }
}
}
