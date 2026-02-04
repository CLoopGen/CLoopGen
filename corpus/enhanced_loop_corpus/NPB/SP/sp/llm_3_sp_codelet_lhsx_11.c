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
// Modify memory access pattern to use a strided access by looping over k first, then j,
// and introducing a stride in the k-loop to simulate non-unit stride access
int stride = 2;
int k_max = (grid_points[2] - 2) / stride;

for (k = 1; k <= k_max; k++) {
    int k_index = k * stride;
    for (j = 1; j <= grid_points[1] - 2; j++) {
        // Access with strided pattern in k dimension
        if (k_index <= grid_points[2] - 2) {
            lhs[2][i][j][k_index] = lhs[2][i][j][k_index] + comz5;
            lhs[3][i][j][k_index] = lhs[3][i][j][k_index] - comz4;
            lhs[4][i][j][k_index] = lhs[4][i][j][k_index] + comz1;
            lhs[1][i + 1][j][k_index] = lhs[1][i + 1][j][k_index] - comz4;
            lhs[2][i + 1][j][k_index] = lhs[2][i + 1][j][k_index] + comz6;
            lhs[3][i + 1][j][k_index] = lhs[3][i + 1][j][k_index] - comz4;
            lhs[4][i + 1][j][k_index] = lhs[4][i + 1][j][k_index] + comz1;
        }
    }
}
}
