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
            int idx = ((m * 65 + i) * 65 + j) * 65 + k;
            int idx_k1 = ((m * 65 + i) * 65 + j) * 65 + (k + 1);
            int idx_k2 = ((m * 65 + i) * 65 + j) * 65 + (k + 2);
            rhs[0][0][0][0] = rhs[0][0][0][0]; // dummy access to maintain array use
            *((double*)&rhs + idx) = *((double*)&rhs + idx) - dssp * (5. * *((double*)&u + idx) - 4. * *((double*)&u + idx_k1) + *((double*)&u + idx_k2));
        }
    }
}
}
