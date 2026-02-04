#include <stdio.h>

extern  int grid_points[3];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;



void loop(){
int indices_i[65], indices_j[65], indices_k[65];
for (int idx = 0; idx < grid_points[0]; idx++) indices_i[idx] = idx;
for (int idx = 0; idx < grid_points[1]; idx++) indices_j[idx] = idx;
for (int idx = 0; idx < grid_points[2]; idx++) indices_k[idx] = idx;

for (n = 0; n < 15; n++) {
    for (int ii = 0; ii < grid_points[0]; ii++) {
        int i = indices_i[ii];
        for (int jj = 0; jj < grid_points[1]; jj++) {
            int j = indices_j[jj];
            for (int kk = 0; kk < grid_points[2]; kk++) {
                int k = indices_k[kk];
                lhs[n][i][j][k] = 0.;
            }
        }
    }
}
}
