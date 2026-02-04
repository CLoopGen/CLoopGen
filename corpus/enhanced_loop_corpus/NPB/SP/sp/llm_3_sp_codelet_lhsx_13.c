#include <stdio.h>

extern  int grid_points[3];
extern  double comz1;
extern  double comz4;
extern  double comz5;
extern  double comz6;
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
// Modify access pattern to use strided access across the i-dimension with precomputed offsets
int offset1 = i;
int offset2 = i + 1;
for (j = 1; j <= grid_points[1] - 2; j += 2) {  // Stride of 2 in j-loop for strided access
    for (k = 1; k <= grid_points[2] - 2; k += 2) { // Stride of 2 in k-loop
        // Access elements with gaps, creating a strided memory pattern
        lhs[0][offset1][j][k] += comz1;
        lhs[1][offset1][j][k] -= comz4;
        lhs[2][offset1][j][k] += comz6;
        lhs[3][offset1][j][k] -= comz4;
        lhs[0][offset2][j][k] += comz1;
        lhs[1][offset2][j][k] -= comz4;
        lhs[2][offset2][j][k] += comz5;
        
        // Also process adjacent points if within bounds (to maintain correctness)
        if (j+1 <= grid_points[1]-2) {
            lhs[0][offset1][j+1][k] += comz1;
            lhs[1][offset1][j+1][k] -= comz4;
            lhs[2][offset1][j+1][k] += comz6;
            lhs[3][offset1][j+1][k] -= comz4;
            lhs[0][offset2][j+1][k] += comz1;
            lhs[1][offset2][j+1][k] -= comz4;
            lhs[2][offset2][j+1][k] += comz5;
        }
        if (k+1 <= grid_points[2]-2) {
            lhs[0][offset1][j][k+1] += comz1;
            lhs[1][offset1][j][k+1] -= comz4;
            lhs[2][offset1][j][k+1] += comz6;
            lhs[3][offset1][j][k+1] -= comz4;
            lhs[0][offset2][j][k+1] += comz1;
            lhs[1][offset2][j][k+1] -= comz4;
            lhs[2][offset2][j][k+1] += comz5;
        }
    }
}
}
