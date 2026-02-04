#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int k1;
extern int m;



void loop(){
for (m = 3; m < 5; m++) {
    n = (m - 3 + 1) * 5;
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (i = 1; i <= grid_points[0] - 2; i++) {
            double temp_rhs = rhs[m][i][j][k1];
            for (int offset = 0; offset < 1; offset++) {
                rhs[m][i][j + offset][k] = rhs[m][i][j + offset][k] - lhs[n + 3][i][j + offset][k] * temp_rhs;
            }
        }
    }
}
}
