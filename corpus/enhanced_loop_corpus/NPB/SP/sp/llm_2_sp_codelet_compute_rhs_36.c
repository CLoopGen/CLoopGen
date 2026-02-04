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
        for (k = 1; k <= grid_points[2] - 2; k++) {
            int idx = m * 65*65*65 + i * 65*65 + j * 65 + k;
            int idx_u_jm1 = m * 65*65*65 + i * 65*65 + (j - 1) * 65 + k;
            int idx_u_j   = m * 65*65*65 + i * 65*65 + j     * 65 + k;
            int idx_u_jp1 = m * 65*65*65 + i * 65*65 + (j + 1) * 65 + k;
            int idx_u_jp2 = m * 65*65*65 + i * 65*65 + (j + 2) * 65 + k;
            ((double*)rhs)[idx] = ((double*)rhs)[idx] - dssp * (-4. * ((double*)u)[idx_u_jm1] + 6. * ((double*)u)[idx_u_j] - 4. * ((double*)u)[idx_u_jp1] + ((double*)u)[idx_u_jp2]);
        }
    }
}
}
