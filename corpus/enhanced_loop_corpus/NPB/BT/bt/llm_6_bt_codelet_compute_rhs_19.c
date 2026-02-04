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
    for (j = 1; j < grid_points[1] - 1; j++) {
        for (k = 1; k < grid_points[2] - 1; k++) {
            double temp_rhs[5];
            // Introduce temporary local storage to remove immediate WAW and RAW dependencies
            // This creates a two-phase update: read all u values, compute, then write back
            for (m = 0; m < 5; m++) {
                temp_rhs[m] = rhs[i][j][k][m] - dssp * (-4. * u[i - 1][j][k][m] + 6. * u[i][j][k][m] - 4. * u[i + 1][j][k][m] + u[i + 2][j][k][m]);
            }
            // Now write the computed values in a separate loop to decouple read and write operations
            for (m = 0; m < 5; m++) {
                rhs[i][j][k][m] = temp_rhs[m];
            }
        }
    }
}
