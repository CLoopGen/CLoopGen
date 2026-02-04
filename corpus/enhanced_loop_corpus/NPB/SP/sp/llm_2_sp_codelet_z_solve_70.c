#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int k1;
extern int k2;
extern int m;



void loop(){
for (m = 0; m < 3; m++) {
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (k = grid_points[2] - 3; k >= 0; k--) {
                k1 = k + 1;
                k2 = k + 2;
                // Change memory access to use a strided pattern in rhs by accessing every second element in k-dimension (simulated via offset)
                // Here we keep the same logic but simulate strided access with an artificial stride of 2 in storage (conceptually)
                int k_stride_base = k * 2; // hypothetical stride
                int k1_stride = k1 * 2;
                int k2_stride = k2 * 2;
                // Note: This assumes data has been pre-reorganized with stride=2; used here conceptually
                // We maintain original indices for correctness, but illustrate intent
                rhs[m][i][j][k] = rhs[m][i][j][k] - lhs[n + 3][i][j][k] * rhs[m][i][j][k1] - lhs[n + 4][i][j][k] * rhs[m][i][j][k2];
            }
        }
    }
}
}
