#include <stdio.h>

extern  int grid_points[3];
extern  double dssp;
extern  double u[5][65][65][65];
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (m = 0; m < 5; m += 2) {
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (k = 3; k <= grid_points[2] - 4; k += 2) {
                double term = u[m][i][j][k-2] - 4.0*u[m][i][j][k-1] + 6.0*u[m][i][j][k] - 4.0*u[m][i][j][k+1] + u[m][i][j][k+2];
                rhs[m][i][j][k] -= dssp * term;
                if (m + 1 < 5 && k + 1 <= grid_points[2] - 4 - 1) {
                    double term_next = u[m+1][i][j][k-2] - 4.0*u[m+1][i][j][k-1] + 6.0*u[m+1][i][j][k] - 4.0*u[m+1][i][j][k+1] + u[m+1][i][j][k+2];
                    rhs[m+1][i][j][k] -= dssp * term_next;
                }
            }
        }
    }
}
}
