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
    // Variant 2: Consecutive memory access by reordering computation to traverse inner dimensions first
    // We reverse the loop order to improve spatial locality, accessing memory in increasing address order
    const int nx = grid_points[0], ny = grid_points[1], nz = grid_points[2];
    
    for (m = 0; m < 5; m++) {
        for (k = 1; k < nz - 1; k++) {
            for (j = 1; j < ny - 1; j++) {
                for (i = 3; i < nx - 3; i++) {
                    rhs[i][j][k][m] -= dssp * (u[i-2][j][k][m] - 4.0 * u[i-1][j][k][m] 
                                             + 6.0 * u[i][j][k][m] - 4.0 * u[i+1][j][k][m] 
                                             + u[i+2][j][k][m]);
                }
            }
        }
    }
}
