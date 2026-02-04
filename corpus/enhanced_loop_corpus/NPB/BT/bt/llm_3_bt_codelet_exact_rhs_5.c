#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[65][65][65][6];
extern int m;
extern int i;
extern int j;
extern int k;



void loop(){
    // Variant 2: Memory Access Pattern Modification - Consecutive linear indexing to improve spatial locality
    int ni = grid_points[0], nj = grid_points[1], nk = grid_points[2];
    double (*f)[65][65][6] = forcing;
    for (i = 1; i < ni - 1; i++) {
        for (j = 1; j < nj - 1; j++) {
            for (k = 1; k < nk - 1; k++) {
                // Force consecutive memory access by iterating over m last
                double *base = &f[i][j][k][0];
                for (m = 0; m < 5; m++) {
                    base[m] = -1. * base[m];
                }
            }
        }
    }
}
