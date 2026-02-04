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
    // Variant 1: Memory Access Pattern Modification - Use strided access with pointer arithmetic to simulate consecutive memory layout for j-dimension
    int gp0 = grid_points[0];
    int gp2 = grid_points[2];
    double (*restrict rhs_ptr)[65][5] = rhs[i];
    double (*restrict u_ptr)[65][5] = u[i];
    
    for (i = 1; i < gp0 - 1; i++, rhs_ptr = rhs[i], u_ptr = u[i]) {
        for (k = 1; k < gp2 - 1; k++) {
            for (m = 0; m < 5; m++) {
                rhs_ptr[j][k][m] -= dssp * (
                    u_ptr[j-2][k][m] - 
                    4.0 * u_ptr[j-1][k][m] + 
                    6.0 * u_ptr[j][k][m] - 
                    4.0 * u_ptr[j+1][k][m]
                );
            }
        }
    }
}
