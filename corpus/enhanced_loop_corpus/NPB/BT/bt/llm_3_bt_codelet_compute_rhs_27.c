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
    // Variant 2: Memory Access Pattern Modification - Reorder loops to improve spatial locality by moving m to outer level and using direct array indexing with temporary references
    int gp0 = grid_points[0];
    int gp2 = grid_points[2];
    
    for (m = 0; m < 5; m++) {  // Move m to outer loop for better cache reuse across m
        for (i = 1; i < gp0 - 1; i++) {
            for (k = 1; k < gp2 - 1; k++) {
                double *rhs_ikm = &rhs[i][j][k][m];
                double u_jm = u[i][j][k][m];
                double u_jm1 = u[i][j-1][k][m];
                double u_jm2 = u[i][j-2][k][m];
                double u_jp1 = u[i][j+1][k][m];

                *rhs_ikm = *rhs_ikm - dssp * (u_jm2 - 4.0 * u_jm1 + 6.0 * u_jm - 4.0 * u_jp1);
            }
        }
    }
}
