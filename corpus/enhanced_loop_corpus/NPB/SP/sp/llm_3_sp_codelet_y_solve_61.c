#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int j1;
extern int m;



void loop(){
double * __restrict__ rhs_ptr = &rhs[0][0][0][0];
double * __restrict__ lhs_ptr = &lhs[0][0][0][0];
int dim1 = 65, dim2 = 65, dim3 = 65;
for (m = 0; m < 3; m++) {
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            int idx_rhs = ((m * dim1 + i) * dim2 + j) * dim3 + k;
            int idx_lhs = ((n + 3) * dim1 + i) * dim2 + j;
            int idx_rhs2 = ((m * dim1 + i) * dim2 + j1) * dim3 + k;
            rhs_ptr[idx_rhs] = rhs_ptr[idx_rhs] - lhs_ptr[idx_lhs * dim3 + k] * rhs_ptr[idx_rhs2];
        }
    }
}
}
