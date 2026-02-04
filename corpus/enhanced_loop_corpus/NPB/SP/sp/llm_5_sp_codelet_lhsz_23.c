#include <stdio.h>

extern  int grid_points[3];
extern  double comz1;
extern  double comz4;
extern  double comz5;
extern  double comz6;
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        int index_offset = (i > j) ? 1 : 0;
        
        lhs[0][i][j][k + index_offset] = lhs[0][i][j][k + index_offset] + comz1;
        lhs[1][i][j][k + index_offset] = lhs[1][i][j][k + index_offset] - comz4;
        
        if (index_offset == 0) {
            lhs[2][i][j][k] = lhs[2][i][j][k] + comz6;
            lhs[3][i][j][k] = lhs[3][i][j][k] - comz4;
        } else {
            lhs[2][i][j][k + 1] = lhs[2][i][j][k + 1] + comz5;
        }
    }
}
}
