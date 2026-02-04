#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

short all_mv8x8[2][2][4][4][2];
short pred_mv8x8[2][2][4][4][2];

int dir = 1;
int ref = 0;
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
    const int size_i = 4;
    const int size_j = 4;
    const int size_k = 1;
    const int size_l = 1;
    const int size_m = 5;
    const int size_n = 2;

    all_mv = (short******)calloc(size_i, sizeof(short*****));
    pred_mv = (short******)calloc(size_i, sizeof(short*****));

    for (int i_idx = 0; i_idx < size_i; i_idx++) {
        all_mv[i_idx] = (short*****)calloc(size_j, sizeof(short****));
        pred_mv[i_idx] = (short*****)calloc(size_j, sizeof(short****));
        for (int j_idx = 0; j_idx < size_j; j_idx++) {
            all_mv[i_idx][j_idx] = (short****)calloc(size_k, sizeof(short***));
            pred_mv[i_idx][j_idx] = (short****)calloc(size_k, sizeof(short***));
            for (int k_idx = 0; k_idx < size_k; k_idx++) {
                all_mv[i_idx][j_idx][k_idx] = (short***)calloc(size_l, sizeof(short**));
                pred_mv[i_idx][j_idx][k_idx] = (short***)calloc(size_l, sizeof(short**));
                for (int l_idx = 0; l_idx < size_l; l_idx++) {
                    all_mv[i_idx][j_idx][k_idx][l_idx] = (short**)calloc(size_m, sizeof(short*));
                    pred_mv[i_idx][j_idx][k_idx][l_idx] = (short**)calloc(size_m, sizeof(short*));
                    for (int m_idx = 0; m_idx < size_m; m_idx++) {
                        all_mv[i_idx][j_idx][k_idx][l_idx][m_idx] = (short*)calloc(size_n, sizeof(short));
                        pred_mv[i_idx][j_idx][k_idx][l_idx][m_idx] = (short*)calloc(size_n, sizeof(short));
                        for (int n_idx = 0; n_idx < size_n; n_idx++) {
                            all_mv[i_idx][j_idx][k_idx][l_idx][m_idx][n_idx] = rand() % 1000;
                            pred_mv[i_idx][j_idx][k_idx][l_idx][m_idx][n_idx] = rand() % 1000;
                        }
                    }
                }
            }
        }
    }

    dir = 1;
    ref = 0;
    i0 = 0;
    _usr_j0 = 0;
    ii = 4;
    jj = 4;
}