#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int M1[16][16];
extern int M0[4][4][4][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering loops and accessing M0 in row-major like fashion
    for (i = 0; i < 4; i++) {
        for (int i_block = 0; i_block < 4; i_block++) {
            for (int j = 0; j < 4; j++) {
                for (int j_block = 0; j_block < 4; j_block++) {
                    int linear_i = i + i_block * 4;
                    int linear_j = j + j_block * 4;
                    M1[linear_i][linear_j] = M0[i][i_block][j][j_block];
                }
            }
        }
    }
}
