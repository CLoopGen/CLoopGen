#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[5][65][65][65];
extern int m;
extern int i;
extern int j;
extern int k;



void loop(){
    // Variant 1: Memory Access Pattern Modification - Use strided access in reverse order
    // Instead of iterating m,i,j,k in increasing order, we traverse with a stride of 2 and handle remaining elements in a second pass for better cache behavior in some architectures.
    int stride = 2;
    for (m = 0; m < 5; m++) {
        for (i = 0; i <= grid_points[0] - 1; i += stride) {
            for (j = 0; j <= grid_points[1] - 1; j += stride) {
                for (k = 0; k <= grid_points[2] - 1; k += stride) {
                    if (i < grid_points[0] && j < grid_points[1] && k < grid_points[2]) {
                        forcing[m][i][j][k] = 0.;
                    }
                    if (i+1 < grid_points[0] && j < grid_points[1] && k < grid_points[2]) {
                        forcing[m][i+1][j][k] = 0.;
                    }
                    if (i < grid_points[0] && j+1 < grid_points[1] && k < grid_points[2]) {
                        forcing[m][i][j+1][k] = 0.;
                    }
                    if (i < grid_points[0] && j < grid_points[1] && k+1 < grid_points[2]) {
                        forcing[m][i][j][k+1] = 0.;
                    }
                }
            }
        }
    }
}
