#include <stdio.h>

extern  int grid_points[3];
extern  double dttx2;
extern  double speed[65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (k = 1; k <= grid_points[2] - 2; k++) {
                int index;
                double factor = (speed[i][j][k] > 0.0) ? 1.0 : -1.0;

                for (index = 0; index < 5; index++) {
                    lhs[index + 5][i][j][k] = lhs[index][i][j][k];
                    lhs[index + 10][i][j][k] = lhs[index][i][j][k];
                }

                if (factor > 0) {
                    lhs[6][i][j][k] -= dttx2 * speed[i - 1][j][k];
                    lhs[8][i][j][k] += dttx2 * speed[i + 1][j][k];
                } else {
                    lhs[11][i][j][k] += dttx2 * speed[i - 1][j][k];
                    lhs[13][i][j][k] -= dttx2 * speed[i + 1][j][k];
                }
            }
        }
    }
}
