#include <stdio.h>

extern  int grid_points[3];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;



void loop(){
for (n = 0; n < 15; n++) {
    for (i = 0; i < grid_points[0]; i++) {
        for (j = 0; j < grid_points[1]; j++) {
            k = 0;
            if (k < grid_points[2]) {
                do {
                    lhs[n][i][j][k] = 0.;
                    k++;
                } while (k < grid_points[2]);
            }
        }
    }
}
}
