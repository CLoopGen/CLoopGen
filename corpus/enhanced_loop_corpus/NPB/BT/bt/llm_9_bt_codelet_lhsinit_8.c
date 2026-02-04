#include <stdio.h>

extern  int grid_points[3];
extern  double lhs[65][65][65][3][5][5];
extern int i;
extern int j;
extern int k;
extern int m;
extern int n;



void loop(){
    for (i = 0; i < grid_points[0]; i += 2) {
        for (j = 0; j < grid_points[1]; j += 2) {
            for (k = 0; k < grid_points[2]; k += 2) {
                for (m = 0; m < 5; m++) {
                    for (n = 0; n < 5; n++) {
                        double temp = 0.0001;
                        lhs[i][j][k][0][m][n] = temp * temp;
                        lhs[i][j][k][1][m][n] = temp * temp * temp;
                        lhs[i][j][k][2][m][n] = temp / (temp + 1.0);
                    }
                }
            }
        }
    }
}
