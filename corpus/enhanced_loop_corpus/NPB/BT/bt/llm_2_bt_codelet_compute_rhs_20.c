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
    // Variant 1: Modified memory access pattern using strided access with pointer arithmetic
    // Instead of direct indexing, we use a stride-based linear traversal for better cache prediction in some architectures
    double (*restrict rhs_ptr)[65][65][5] = rhs;
    double (*restrict u_ptr)[65][65][5] = u;
    const int nx = grid_points[0], ny = grid_points[1], nz = grid_points[2];
    
    for (i = 3; i < nx - 3; i++) {
        for (j = 1; j < ny - 1; j++) {
            for (k = 1; k < nz - 1; k++) {
                double *rhs_base = &rhs_ptr[i][j][k][0];
                double *u_im2 = &u_ptr[i-2][j][k][0];
                double *u_im1 = &u_ptr[i-1][j][k][0];
                double *u_i   = &u_ptr[i  ][j][k][0];
                double *u_ip1 = &u_ptr[i+1][j][k][0];
                double *u_ip2 = &u_ptr[i+2][j][k][0];
                
                for (m = 0; m < 5; m++) {
                    rhs_base[m] = rhs_base[m] - dssp * (u_im2[m] - 4. * u_im1[m] + 6. * u_i[m] - 4. * u_ip1[m] + u_ip2[m]);
                }
            }
        }
    }
}
