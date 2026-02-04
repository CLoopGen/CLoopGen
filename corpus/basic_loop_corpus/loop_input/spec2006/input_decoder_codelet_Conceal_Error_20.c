#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int mb_y = 10;
int mb_x = 10;
int i;
int block_x;
int block_y;

int mv[2][4][4];

short ***tmp_mv;

void init_vars() {
    const int size_mb = 64;
    const int total_elements = (size_mb * 1024 * 1024) / sizeof(short);
    short *flat_mem = (short *)calloc(total_elements, sizeof(short));
    
    const int outer_dim1 = 100;
    const int outer_dim2 = 100;
    const int inner_dim = 2;
    
    tmp_mv = (short ***)malloc(outer_dim1 * sizeof(short **));
    for (int i = 0; i < outer_dim1; i++) {
        tmp_mv[i] = (short **)malloc(outer_dim2 * sizeof(short *));
        for (int j = 0; j < outer_dim2; j++) {
            int offset = (i * outer_dim2 + j) * inner_dim;
            if (offset + 1 < total_elements) {
                tmp_mv[i][j] = &flat_mem[offset];
            } else {
                tmp_mv[i][j] = &flat_mem[total_elements - 2];
            }
        }
    }
}