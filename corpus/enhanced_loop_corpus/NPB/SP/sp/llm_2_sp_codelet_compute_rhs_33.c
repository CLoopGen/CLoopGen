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
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            int idx = m * 65*65*65 + i * 65*65 + j * 65 + k;
            int idx_im2 = m * 65*65*65 + (i-2) * 65*65 + j * 65 + k;
            int idx_im1 = m * 65*65*65 + (i-1) * 65*65 + j * 65 + k;
            ((double*)rhs)[idx] = ((double*)rhs)[idx] - dssp * (
                ((double*)u)[idx_im2] - 4. * ((double*)u)[idx_im1] + 5. * ((double*)u)[idx]
            );
        }
    }
}
}
