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
// Use strided access by reordering loop to improve spatial locality in k-dimension
// and modify access pattern to traverse with stride in the j-direction
for (k = 1; k <= grid_points[2] - 2; k++) {
    for (i = 1; i <= grid_points[0] - 2; i++) {
        // Access with explicit offsets, simulating strided access due to loop interchange
        lhs[0][i][j][k] += comz1;
        lhs[1][i][j][k] -= comz4;
        lhs[2][i][j][k] += comz6;
        lhs[3][i][j][k] -= comz4;

        // Strided update: accessing j+1 breaks continuity in j, now more noticeable due to i-k loop order
        lhs[0][i][j+1][k] += comz1;
        lhs[1][i][j+1][k] -= comz4;
        lhs[2][i][j+1][k] += comz5;
    }
}
}
