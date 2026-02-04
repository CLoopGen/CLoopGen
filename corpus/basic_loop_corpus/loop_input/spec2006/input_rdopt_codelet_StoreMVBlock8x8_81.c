#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

short all_mv8x8[2][2][4][4][2];
short pred_mv8x8[2][2][4][4][2];
int dir = 0;
int mode = 0;
int ref = 0;
int bw_ref = 0;
int i;
int j;
int i0 = 0;
int _usr_j0 = 0;
int ii;
int jj;

#define j0 _usr_j0

short ******all_mv = NULL;
short ******pred_mv = NULL;

void init_vars() {
    const int dim_i = 64;
    const int dim_j = 64;
    const int dim_dir = 2;
    const int dim_mode = 1;
    const int dim_ref = 2;
    const int dim_bw_ref = 2;
    const int dim_k = 2;

    ii = dim_i;
    jj = dim_j;

    all_mv = (short ******)calloc(dim_i, sizeof(short *****));
    pred_mv = (short ******)calloc(dim_i, sizeof(short *****));

    for (int i_idx = 0; i_idx < dim_i; i_idx++) {
        all_mv[i_idx] = (short *****)calloc(dim_j, sizeof(short ****));
        pred_mv[i_idx] = (short *****)calloc(dim_j, sizeof(short ****));
        for (int j_idx = 0; j_idx < dim_j; j_idx++) {
            all_mv[i_idx][j_idx] = (short ****)calloc(dim_k, sizeof(short ***));
            pred_mv[i_idx][j_idx] = (short ****)calloc(dim_k, sizeof(short ***));
            for (int k_idx = 0; k_idx < dim_k; k_idx++) {
                all_mv[i_idx][j_idx][k_idx] = (short ***)calloc(dim_ref, sizeof(short **));
                pred_mv[i_idx][j_idx][k_idx] = (short ***)calloc(dim_ref, sizeof(short **));
                for (int ref_idx = 0; ref_idx < dim_ref; ref_idx++) {
                    all_mv[i_idx][j_idx][k_idx][ref_idx] = (short **)calloc(dim_mode, sizeof(short *));
                    pred_mv[i_idx][j_idx][k_idx][ref_idx] = (short **)calloc(dim_mode, sizeof(short *));
                    for (int mode_idx = 0; mode_idx < dim_mode; mode_idx++) {
                        all_mv[i_idx][j_idx][k_idx][ref_idx][mode_idx] = (short *)calloc(dim_k, sizeof(short));
                        pred_mv[i_idx][j_idx][k_idx][ref_idx][mode_idx] = (short *)calloc(dim_k, sizeof(short));
                        for (int comp = 0; comp < dim_k; comp++) {
                            all_mv[i_idx][j_idx][k_idx][ref_idx][mode_idx][comp] = rand() % 1024;
                            pred_mv[i_idx][j_idx][k_idx][ref_idx][mode_idx][comp] = rand() % 1024;
                        }
                    }
                }
            }
        }
    }

    dir = 0;
    mode = 0;
    ref = 0;
    bw_ref = 1;
    i0 = 0;
    _usr_j0 = 0;
    ii = 4;
    jj = 4;

    memset(all_mv8x8, 0, sizeof(all_mv8x8));
    memset(pred_mv8x8, 0, sizeof(pred_mv8x8));
}