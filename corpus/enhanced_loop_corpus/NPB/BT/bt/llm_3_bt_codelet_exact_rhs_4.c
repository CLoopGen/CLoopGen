#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[65][65][65][6];
extern int m;
extern int i;
extern int j;
extern int k;



void loop(){
    // Variant 2: Strided memory access - access every second element in the k-dimension, then fill in
    // This creates a non-unit stride pattern to simulate irregular access useful in certain stencil prep
    int k;
    // First pass: even indices in k
    for (i = 0; i < grid_points[0]; i++) {
        for (j = 0; j < grid_points[1]; j++) {
            for (k = 0; k < grid_points[2]; k += 2) {
                for (m = 0; m < 5; m++) {
                    forcing[i][j][k][m] = 0.;
                }
            }
        }
    }
    // Second pass: odd indices in k
    for (i = 0; i < grid_points[0]; i++) {
        for (j = 0; j < grid_points[1]; j++) {
            for (k = 1; k < grid_points[2]; k += 2) {
                for (m = 0; m < 5; m++) {
                    forcing[i][j][k][m] = 0.;
                }
            }
        }
    }
}
