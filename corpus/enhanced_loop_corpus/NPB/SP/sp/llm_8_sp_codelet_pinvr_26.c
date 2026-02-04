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
        for (k = 1; k <= grid_points[2] - 2; k += 2) {
            r1 = rhs[0][i][j][k];
            r2 = rhs[1][i][j][k];
            r3 = rhs[2][i][j][k];
            r4 = rhs[3][i][j][k];
            r5 = rhs[4][i][j][k];
            t1 = bt * r1;
            t2 = 0.5 * (r4 + r5);
            rhs[0][i][j][k] = bt * (r4 - r5);
            rhs[1][i][j][k] = -r3;
            rhs[2][i][j][k] = r2;
            rhs[3][i][j][k] = -t1 + t2;
            rhs[4][i][j][k] = t1 + t2;

            if (k + 1 < grid_points[2] - 1) {
                double r1_next = rhs[0][i][j][k+1];
                double r2_next = rhs[1][i][j][k+1];
                double r3_next = rhs[2][i][j][k+1];
                double r4_next = rhs[3][i][j][k+1];
                double r5_next = rhs[4][i][j][k+1];
                double t1_next = bt * r1_next;
                double t2_next = 0.5 * (r4_next + r5_next);
                rhs[0][i][j][k+1] = bt * (r4_next - r5_next);
                rhs[1][i][j][k+1] = -r3_next;
                rhs[2][i][j][k+1] = r2_next;
                rhs[3][i][j][k+1] = -t1_next + t2_next;
                rhs[4][i][j][k+1] = t1_next + t2_next;
            }
        }
    }
}
}
