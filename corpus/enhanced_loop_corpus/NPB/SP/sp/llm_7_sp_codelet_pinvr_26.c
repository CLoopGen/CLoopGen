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
double prev_t1 = 0.0, prev_t2 = 0.0;
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            r1 = rhs[0][i][j][k];
            r2 = rhs[1][i][j][k];
            r3 = rhs[2][i][j][k];
            r4 = rhs[3][i][j][k];
            r5 = rhs[4][i][j][k];

            t1 = bt * r1;
            t2 = 0.5 * (r4 + r5);

            double delayed_rhs0 = bt * (r4 - r5);
            double delayed_rhs3 = -t1 + t2;
            double delayed_rhs4 = t1 + t2;

            if (k > 1) {
                rhs[3][i][j][k-1] += prev_t1;
                rhs[4][i][j][k-1] -= prev_t2;
            }

            rhs[0][i][j][k] = delayed_rhs0;
            rhs[1][i][j][k] = -r3;
            rhs[2][i][j][k] = r2;

            prev_t1 = t1;
            prev_t2 = t2;
        }
        if (grid_points[2] > 2) {
            rhs[3][i][j][grid_points[2]-2] += prev_t1;
            rhs[4][i][j][grid_points[2]-2] -= prev_t2;
        }
    }
}
}
