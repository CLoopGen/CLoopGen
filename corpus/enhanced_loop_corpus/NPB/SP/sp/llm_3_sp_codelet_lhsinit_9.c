#include <stdio.h>

extern  int grid_points[3];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;



void loop(){
int indices[3];
for (n = 0; n < 3; n++) {
    indices[n] = 5 * n + 2;
}
for (i = 0; i < grid_points[0]; i++) {
    for (j = 0; j < grid_points[1]; j++) {
        for (k = 0; k < grid_points[2]; k++) {
            for (n = 0; n < 3; n++) {
                lhs[indices[n]][i][j][k] = 1.;
            }
        }
    }
}
}
