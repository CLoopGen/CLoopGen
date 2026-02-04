#include <stdio.h>

extern  int grid_points[3];
extern  double dssp;
extern  double u[65][65][65][5];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (i = 1; i < grid_points[0] - 1; i++) {
    for (m = 0; m < 5; m++) {
        for (j = 1; j < grid_points[1] - 1; j++) {
            int idx_k   = k;
            int idx_kp1 = k + 1;
            int idx_kp2 = k + 2;
            rhs[i][j][idx_k][m] = rhs[i][j][idx_k][m] - 
                dssp * (5. * u[i][j][idx_k][m] - 4. * u[i][j][idx_kp1][m] + u[i][j][idx_kp2][m]);
        }
    }
}
}
