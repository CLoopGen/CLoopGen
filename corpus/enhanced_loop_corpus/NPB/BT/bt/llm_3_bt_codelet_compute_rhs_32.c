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
    // Variant 2: Strided Memory Access using pointer arithmetic with fixed stride
    // We use explicit pointer arithmetic to access array elements with stride,
    // simulating a strided access pattern that may occur in blocked or tiled codes.
    // Here, we compute base pointers for each [i][j] slice and step through k with offset arithmetic.

    long long int idx_base, idx_km2, idx_km1, idx_k, idx_kp1, idx_kp2;
    double *rhs_ptr;
    const double *u_ptr;

    for (i = 1; i < grid_points[0] - 1; i++) {
        for (j = 1; j < grid_points[1] - 1; j++) {
            for (k = 3; k < grid_points[2] - 3; k++) {
                // Compute base index for [i][j][k] slice
                idx_base = ((i * 65 + j) * 65 + k) * 5;
                for (m = 0; m < 5; m++) {
                    idx_km2 = ((i * 65 + j) * 65 + (k - 2)) * 5 + m;
                    idx_km1 = ((i * 65 + j) * 65 + (k - 1)) * 5 + m;
                    idx_k   = idx_base + m;
                    idx_kp1 = ((i * 65 + j) * 65 + (k + 1)) * 5 + m;
                    idx_kp2 = ((i * 65 + j) * 65 + (k + 2)) * 5 + m;

                    rhs_ptr = &rhs[0][0][0][0] + idx_k;
                    u_ptr = &u[0][0][0][0];

                    rhs_ptr[m] -= dssp * (u_ptr[idx_km2] - 4.0 * u_ptr[idx_km1] 
                                        + 6.0 * u_ptr[idx_k] - 4.0 * u_ptr[idx_kp1] 
                                        + u_ptr[idx_kp2]);
                }
            }
        }
    }
}
