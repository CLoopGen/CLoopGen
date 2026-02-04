#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[65][65][65][5];
extern double rms[5];
extern int i;
extern int j;
extern int k;
extern int m;
extern double add;



void loop(){
for (i = 2; i < grid_points[0] - 2; i += 2) {
    for (j = 2; j < grid_points[1] - 2; j += 2) {
        for (k = 2; k < grid_points[2] - 2; k += 2) {
            for (m = 0; m < 5; m++) {
                double val1 = rhs[i][j][k][m];
                double val2 = rhs[i+1][j+1][k+1][m];
                double val3 = rhs[i-1][j-1][k-1][m];
                add = (val1 + val2 + val3) / 3.0;
                rms[m] = rms[m] + add * add;
            }
        }
    }
}
}
