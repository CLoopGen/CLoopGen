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
for (k = 1; k <= grid_points[2] - 2; k += 2) {
    for (j = 1; j <= grid_points[1] - 2; j += 2) {
        for (m = 0; m < 5; m++) {
            rhs[m][i][j+0][k+0] = rhs[m][i][j+0][k+0] - dssp * (u[m][i-2][j+0][k+0] - 4.*u[m][i-1][j+0][k+0] + 6.*u[m][i][j+0][k+0] - 4.*u[m][i+1][j+0][k+0]);
            rhs[m][i][j+0][k+1] = rhs[m][i][j+0][k+1] - dssp * (u[m][i-2][j+0][k+1] - 4.*u[m][i-1][j+0][k+1] + 6.*u[m][i][j+0][k+1] - 4.*u[m][i+1][j+0][k+1]);
            rhs[m][i][j+1][k+0] = rhs[m][i][j+1][k+0] - dssp * (u[m][i-2][j+1][k+0] - 4.*u[m][i-1][j+1][k+0] + 6.*u[m][i][j+1][k+0] - 4.*u[m][i+1][j+1][k+0]);
            rhs[m][i][j+1][k+1] = rhs[m][i][j+1][k+1] - dssp * (u[m][i-2][j+1][k+1] - 4.*u[m][i-1][j+1][k+1] + 6.*u[m][i][j+1][k+1] - 4.*u[m][i+1][j+1][k+1]);
        }
    }
}
}
