#include <stdio.h>

extern  int grid_points[3];
extern  double dt;
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    int idx, m;
    int total_i = grid_points[0] - 2;
    int total_j = grid_points[1] - 2;
    int total_k = grid_points[2] - 2;
    for (idx = 0; idx < total_i * total_j * total_k; idx++) {
        int flat_i = (idx / (total_j * total_k)) + 1;
        int flat_j = ((idx / total_k) % total_j) + 1;
        int flat_k = (idx % total_k) + 1;
        for (m = 0; m < 5; m++) {
            rhs[flat_i][flat_j][flat_k][m] *= dt;
        }
    }
}
