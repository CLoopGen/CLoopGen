#include <stdio.h>

extern  int grid_points[3];
extern  double dssp;
extern  double u[5][65][65][65];
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (m = 0; m < 5; m++) {
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            int idx = m * 65*65*65 + i * 65*65 + j * 65 + k;
            int u_idx_k1 = m * 65*65*65 + i * 65*65 + j * 65 + (k - 1);
            int u_idx_k = m * 65*65*65 + i * 65*65 + j * 65 + k;
            int u_idx_k1p = m * 65*65*65 + i * 65*65 + j * 65 + (k + 1);
            int u_idx_k2p = m * 65*65*65 + i * 65*65 + j * 65 + (k + 2);
            rhs[0][0][0][0] = ((double*)rhs)[idx]; // Base access to rhs via flat indexing
            ((double*)rhs)[idx] = ((double*)rhs)[idx] - dssp * (-4. * ((double*)u)[u_idx_k1] + 6. * ((double*)u)[u_idx_k] - 4. * ((double*)u)[u_idx_k1p] + ((double*)u)[u_idx_k2p]);
        }
    }
}
}
