#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

short all_mv8x8[2][2][4][4][2];
short pred_mv8x8[2][2][4][4][2];
int dir = 1;
int mode = 0;
int fw_ref = 0;
int i;
int j;
int i0 = 0;
int _usr_j0 = 0;
int ii = 4;
int jj = 4;

#define j0 _usr_j0

short ******all_mv;
short ******pred_mv;

void init_vars() {
    const int dim1 = 4;
    const int dim2 = 4;
    const int dim3 = 1;
    const int dim4 = 1;
    const int dim5 = 1;
    const int dim6 = 2;

    size_t total_size = (size_t)dim1 * dim2 * dim3 * dim4 * dim5 * dim6 * sizeof(short);
    short *data_pool = (short*)calloc(total_size * 2, 1);
    if (!data_pool) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    short *data_pool2 = data_pool + total_size / sizeof(short);

    all_mv = (short******)calloc(dim1, sizeof(short*****));
    pred_mv = (short******)calloc(dim1, sizeof(short*****));
    if (!all_mv || !pred_mv) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int a = 0; a < dim1; a++) {
        all_mv[a] = (short*****)calloc(dim2, sizeof(short****));
        pred_mv[a] = (short*****)calloc(dim2, sizeof(short****));
        if (!all_mv[a] || !pred_mv[a]) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        for (int b = 0; b < dim2; b++) {
            all_mv[a][b] = (short****)calloc(dim3, sizeof(short***));
            pred_mv[a][b] = (short****)calloc(dim3, sizeof(short***));
            if (!all_mv[a][b] || !pred_mv[a][b]) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            for (int c = 0; c < dim3; c++) {
                all_mv[a][b][c] = (short***)calloc(dim4, sizeof(short**));
                pred_mv[a][b][c] = (short***)calloc(dim4, sizeof(short**));
                if (!all_mv[a][b][c] || !pred_mv[a][b][c]) {
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(1);
                }
                for (int d = 0; d < dim4; d++) {
                    all_mv[a][b][c][d] = (short**)calloc(dim5, sizeof(short*));
                    pred_mv[a][b][c][d] = (short**)calloc(dim5, sizeof(short*));
                    if (!all_mv[a][b][c][d] || !pred_mv[a][b][c][d]) {
                        fprintf(stderr, "Memory allocation failed\n");
                        exit(1);
                    }
                    for (int e = 0; e < dim5; e++) {
                        all_mv[a][b][c][d][e] = data_pool + ((((a * dim2 + b) * dim3 + c) * dim4 + d) * dim5 + e) * dim6;
                        pred_mv[a][b][c][d][e] = data_pool2 + ((((a * dim2 + b) * dim3 + c) * dim4 + d) * dim5 + e) * dim6;
                    }
                }
            }
        }
    }

    for (size_t idx = 0; idx < total_size / sizeof(short); idx++) {
        data_pool[idx] = (short)(idx % 32767);
        data_pool2[idx] = (short)(idx % 32767);
    }

    dir = 1;
    mode = 0;
    fw_ref = 0;
    i0 = 0;
    _usr_j0 = 0;
    ii = 4;
    jj = 4;
}