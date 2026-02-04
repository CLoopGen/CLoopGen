#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern double rms[5];
extern int i;
extern int j;
extern int k;
extern int m;
extern double add;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i += 2) {
    for (j = 1; j <= grid_points[1] - 2; j += 2) {
        for (k = 1; k <= grid_points[2] - 2; k += 2) {
            for (m = 0; m < 5; m++) {
                add = rhs[m][i][j][k];
                rms[m] = rms[m] + add * add;
                add = rhs[m][i-1][j][k];
                rms[m] = rms[m] + add * add;
                add = rhs[m][i][j-1][k];
                rms[m] = rms[m] + add * add;
                add = rhs[m][i][j][k-1];
                rms[m] = rms[m] + add * add;
            }
        }
    }
}
}
