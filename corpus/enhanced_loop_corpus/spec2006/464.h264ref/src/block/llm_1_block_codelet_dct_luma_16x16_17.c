#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int M1[16][16];
extern int M0[4][4][4][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int block_i = 0; block_i < 4; block_i++) {
    for (int block_j = 0; block_j < 4; block_j++) {
        for (int elem_i = 0; elem_i < 4; elem_i++) {
            for (int elem_j = 0; elem_j < 4; elem_j++) {
                int i = block_i * 4 + elem_i;
                int j = block_j * 4 + elem_j;
                M1[i][j] = M0[block_i][elem_i][block_j][elem_j];
            }
        }
    }
}
}
