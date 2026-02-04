#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

short ref = 0;
int list = 0;
int blocktype = 0;
short mv_x = 16;
short mv_y = -8;
int i = 0;
int j = 0;
int block_x = 0;
int block_y = 0;
int bsx = 128;
int bsy = 128;
int h4x4blkno = 0;
int v4x4blkno = 0;

short ***mv_array = NULL;
short ******all_mv = NULL;

void init_vars() {
    int size_4x4_x = (bsx >> 2) + 16;
    int size_4x4_y = (bsy >> 2) + 16;
    int all_mv_dim0 = size_4x4_x + 16;
    int all_mv_dim1 = size_4x4_y + 16;
    int all_mv_dim2 = 2;
    int all_mv_dim3 = 2;
    int all_mv_dim4 = 2;
    int all_mv_dim5 = 2;

    // Allocate mv_array: [size_4x4_x][size_4x4_y][2]
    mv_array = (short***)calloc(all_mv_dim0, sizeof(short**));
    for (int a = 0; a < size_4x4_x; a++) {
        mv_array[a] = (short**)calloc(size_4x4_y, sizeof(short*));
        for (int b = 0; b < size_4x4_y; b++) {
            mv_array[a][b] = (short*)calloc(2, sizeof(short));
        }
    }

    // Allocate all_mv: [all_mv_dim0][all_mv_dim1][all_mv_dim2][all_mv_dim3][all_mv_dim4][all_mv_dim5]
    all_mv = (short******)calloc(all_mv_dim0, sizeof(short*****));
    for (int a = 0; a < all_mv_dim0; a++) {
        all_mv[a] = (short*****)calloc(all_mv_dim1, sizeof(short****));
        for (int b = 0; b < all_mv_dim1; b++) {
            all_mv[a][b] = (short****)calloc(all_mv_dim2, sizeof(short***));
            for (int c = 0; c < all_mv_dim2; c++) {
                all_mv[a][b][c] = (short***)calloc(all_mv_dim3, sizeof(short**));
                for (int d = 0; d < all_mv_dim3; d++) {
                    all_mv[a][b][c][d] = (short**)calloc(all_mv_dim4, sizeof(short*));
                    for (int e = 0; e < all_mv_dim4; e++) {
                        all_mv[a][b][c][d][e] = (short*)calloc(all_mv_dim5, sizeof(short));
                    }
                }
            }
        }
    }

    block_x = 8;
    block_y = 8;
    h4x4blkno = 8;
    v4x4blkno = 8;
    ref = 0;
    list = 0;
    blocktype = 0;
}