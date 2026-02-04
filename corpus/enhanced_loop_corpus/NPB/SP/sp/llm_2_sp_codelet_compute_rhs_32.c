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
            int idx = ((m * 65 + i) * 65 + j) * 65 + k;
            int idx_m2 = ((m * 65 + (i - 2)) * 65 + j) * 65 + k;
            int idx_m1 = ((m * 65 + (i - 1)) * 65 + j) * 65 + k;
            int idx_p1 = ((m * 65 + (i + 1)) * 65 + j) * 65 + k;
            rhs[0][0][0][idx] = rhs[0][0][0][idx] - dssp * (u[0][0][0][idx_m2] - 4. * u[0][0][0][idx_m1] + 6. * u[0][0][0][idx] - 4. * u[0][0][0][idx_p1]);
        }
    }
}
}
