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
for (i = 2; i <= grid_points[0] - 3; i++) {
    for (j = 2; j <= grid_points[1] - 3; j++) {
        for (k = 2; k <= grid_points[2] - 3; k++) {
            r1 = 0.9 * rhs[0][i][j][k] + 0.05 * (rhs[0][i-1][j][k] + rhs[0][i+1][j][k] +
                                                rhs[0][i][j-1][k] + rhs[0][i][j+1][k] +
                                                rhs[0][i][j][k-1] + rhs[0][i][j][k+1]);
            r2 = 0.9 * rhs[1][i][j][k] + 0.05 * (rhs[1][i-1][j][k] + rhs[1][i+1][j][k] +
                                                rhs[1][i][j-1][k] + rhs[1][i][j+1][k] +
                                                rhs[1][i][j][k-1] + rhs[1][i][j][k+1]);
            r3 = 0.9 * rhs[2][i][j][k] + 0.05 * (rhs[2][i-1][j][k] + rhs[2][i+1][j][k] +
                                                rhs[2][i][j-1][k] + rhs[2][i][j+1][k] +
                                                rhs[2][i][j][k-1] + rhs[2][i][j][k+1]);
            r4 = 0.9 * rhs[3][i][j][k] + 0.05 * (rhs[3][i-1][j][k] + rhs[3][i+1][j][k] +
                                                rhs[3][i][j-1][k] + rhs[3][i][j+1][k] +
                                                rhs[3][i][j][k-1] + rhs[3][i][j][k+1]);
            r5 = 0.9 * rhs[4][i][j][k] + 0.05 * (rhs[4][i-1][j][k] + rhs[4][i+1][j][k] +
                                                rhs[4][i][j-1][k] + rhs[4][i][j+1][k] +
                                                rhs[4][i][j][k-1] + rhs[4][i][j][k+1]);
            t1 = bt * r3;
            t2 = 0.5 * (r4 + r5);
            rhs[0][i][j][k] = -r2;
            rhs[1][i][j][k] = r1;
            rhs[2][i][j][k] = bt * (r4 - r5);
            rhs[3][i][j][k] = -t1 + t2;
            rhs[4][i][j][k] = t1 + t2;
        }
    }
}
}
