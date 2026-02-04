#include <stdio.h>

extern  int grid_points[3];
extern  double dssp;
extern  double u[65][65][65][5];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (i = 1; i < grid_points[0] - 1; i++) {
    for (m = 0; m < 5; m++) {
        for (j = 1; j < grid_points[1] - 1; j++) {
            int idx = ((i * 65 + j) * 65 + k) * 5 + m;
            int u_idx_k2 = ((i * 65 + j) * 65 + (k - 2)) * 5 + m;
            int u_idx_k1 = ((i * 65 + j) * 65 + (k - 1)) * 5 + m;
            int u_idx_k  = ((i * 65 + j) * 65 + k) * 5 + m;
            ((double*)rhs)[idx] = ((double*)rhs)[idx] - dssp * (
                ((double*)u)[u_idx_k2] - 4. * ((double*)u)[u_idx_k1] + 5. * ((double*)u)[u_idx_k]
            );
        }
    }
}
}
