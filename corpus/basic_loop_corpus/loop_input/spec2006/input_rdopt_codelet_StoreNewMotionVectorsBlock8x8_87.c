#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define j0 _usr_j0

short all_mv8x8[2][2][4][4][2];
short pred_mv8x8[2][2][4][4][2];
int dir;
int fw_ref;
int i;
int j;
int i0;
int _usr_j0;
int ii;
int jj;

short ******all_mv;
short ******pred_mv;

void init_vars() {
    dir = 0;
    fw_ref = 0;
    i0 = 0;
    _usr_j0 = 0;

    ii = 4;
    jj = 4;

    int size = 4;
    all_mv = (short******)calloc(size, sizeof(short*****));
    pred_mv = (short******)calloc(size, sizeof(short*****));

    for (int i_idx = 0; i_idx < size; i_idx++) {
        all_mv[i_idx] = (short*****)calloc(size, sizeof(short****));
        pred_mv[i_idx] = (short*****)calloc(size, sizeof(short****));
        for (int j_idx = 0; j_idx < size; j_idx++) {
            all_mv[i_idx][j_idx] = (short****)calloc(1, sizeof(short***));
            pred_mv[i_idx][j_idx] = (short****)calloc(1, sizeof(short***));
            all_mv[i_idx][j_idx][0] = (short***)calloc(16, sizeof(short**));
            pred_mv[i_idx][j_idx][0] = (short***)calloc(16, sizeof(short**));
            for (int ref = 0; ref < 16; ref++) {
                all_mv[i_idx][j_idx][0][ref] = (short**)calloc(5, sizeof(short*));
                pred_mv[i_idx][j_idx][0][ref] = (short**)calloc(5, sizeof(short*));
                for (int idx4 = 0; idx4 < 5; idx4++) {
                    all_mv[i_idx][j_idx][0][ref][idx4] = (short*)calloc(2, sizeof(short));
                    pred_mv[i_idx][j_idx][0][ref][idx4] = (short*)calloc(2, sizeof(short));
                    all_mv[i_idx][j_idx][0][ref][idx4][0] = rand() % 1000;
                    all_mv[i_idx][j_idx][0][ref][idx4][1] = rand() % 1000;
                    pred_mv[i_idx][j_idx][0][ref][idx4][0] = rand() % 1000;
                    pred_mv[i_idx][j_idx][0][ref][idx4][1] = rand() % 1000;
                }
            }
        }
    }
}