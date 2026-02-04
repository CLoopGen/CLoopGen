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
for (m = 0; m < 3; m++) {
    i = 1;
    if (i <= grid_points[0] - 2) {
        j = 1;
        if (j <= grid_points[1] - 2) {
            do {
                rhs[m][i][j][k] = rhs[m][i][j][k] - lhs[n + 3][i][j][k] * rhs[m][i][j][k1];
                j++;
            } while (j <= grid_points[1] - 2);
            i++;
        }
    }
}
}
