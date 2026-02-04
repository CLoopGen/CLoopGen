#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define j0 _usr_j0

short all_mv8x8[2][2][4][4][2];
short pred_mv8x8[2][2][4][4][2];
int dir = 0;
int mode = 0;
int bw_ref = 1;
int i;
int j;
int i0 = 0;
int _usr_j0 = 0;
int ii;
int jj;

short ******all_mv;
short ******pred_mv;

void init_vars() {
    ii = 4;
    jj = 4;

    size_t total_size = 0;
    const size_t element_size = sizeof(short);
    const size_t target_bytes = 64 * 1024 * 1024; // 64 MB
    const int fixed_outer_dims[6] = {4, 4, 2, 2, 4, 4}; 
    size_t base_size = fixed_outer_dims[0] * fixed_outer_dims[1] * fixed_outer_dims[2] *
                       fixed_outer_dims[3] * fixed_outer_dims[4] * fixed_outer_dims[5];
    size_t elements_per_block = target_bytes / (element_size * base_size);
    if (elements_per_block == 0) elements_per_block = 1;

    all_mv = (short******)calloc(fixed_outer_dims[0], sizeof(short*****));
    pred_mv = (short******)calloc(fixed_outer_dims[0], sizeof(short*****));
    for (int a = 0; a < fixed_outer_dims[0]; a++) {
        all_mv[a] = (short*****)calloc(fixed_outer_dims[1], sizeof(short****));
        pred_mv[a] = (short*****)calloc(fixed_outer_dims[1], sizeof(short****));
        for (int b = 0; b < fixed_outer_dims[1]; b++) {
            all_mv[a][b] = (short****)calloc(fixed_outer_dims[2], sizeof(short***));
            pred_mv[a][b] = (short****)calloc(fixed_outer_dims[2], sizeof(short***));
            for (int c = 0; c < fixed_outer_dims[2]; c++) {
                all_mv[a][b][c] = (short***)calloc(fixed_outer_dims[3], sizeof(short**));
                pred_mv[a][b][c] = (short***)calloc(fixed_outer_dims[3], sizeof(short**));
                for (int d = 0; d < fixed_outer_dims[3]; d++) {
                    all_mv[a][b][c][d] = (short**)calloc(fixed_outer_dims[4], sizeof(short*));
                    pred_mv[a][b][c][d] = (short**)calloc(fixed_outer_dims[4], sizeof(short*));
                    for (int e = 0; e < fixed_outer_dims[4]; e++) {
                        size_t alloc_size = elements_per_block * sizeof(short);
                        all_mv[a][b][c][d][e] = (short*)calloc(2, sizeof(short));
                        pred_mv[a][b][c][d][e] = (short*)calloc(2, sizeof(short));
                        for (int f = 0; f < 2; f++) {
                            all_mv[a][b][c][d][e][f] = rand() % 1000;
                            pred_mv[a][b][c][d][e][f] = rand() % 1000;
                        }
                    }
                }
            }
        }
    }
}