#include <stdio.h>

extern  int grid_points[3];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;



void loop(){
for (n = 0; n < 15; n++) {
    for (i = 1; i < grid_points[0]-1; i++) {
        for (j = 1; j < grid_points[1]-1; j++) {
            for (k = 1; k < grid_points[2]-1; k++) {
                lhs[n][i][j][k] = 
                    lhs[n][i+1][j][k] + 
                    lhs[n][i-1][j][k] + 
                    lhs[n][i][j+1][k] + 
                    lhs[n][i][j-1][k] + 
                    lhs[n][i][j][k+1] + 
                    lhs[n][i][j][k-1];
            }
        }
    }
}
}
