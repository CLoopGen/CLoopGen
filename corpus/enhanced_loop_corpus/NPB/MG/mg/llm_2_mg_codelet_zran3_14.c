#include <stdio.h>

extern double ***z;
extern int m0;
extern int i;
extern int j1[10][2];
extern int j2[10][2];
extern int j3[10][2];



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of indirect indexing via j1, j2, j3, we assume a scenario where indices are adjusted to access consecutive elements
    // We reverse the loop order and use direct offset from a base index for spatial locality
    int base_i = j3[m0][0];
    int base_j = j2[m0][0];
    int len = j1[10 - 1][0] - j1[m0][0] + 1;
    for (i = 0; i < len; i++) {
        z[base_i][base_j][j1[m0 + i][0]] = -1.;
    }
}
