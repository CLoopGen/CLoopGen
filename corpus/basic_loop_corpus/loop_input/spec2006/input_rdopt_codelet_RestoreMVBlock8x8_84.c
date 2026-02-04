#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

short all_mv8x8[2][2][4][4][2];
short pred_mv8x8[2][2][4][4][2];
int dir;
int mode;
int bw_ref;
int i;
int j;
int i0;
int _usr_j0;
int ii;
int jj;

short ******all_mv;
short ******pred_mv;

#define j0 _usr_j0

void init_vars() {
    dir = 1;
    mode = 1;
    bw_ref = 0;
    i0 = 0;
    j0 = 0;
    ii = 64;
    jj = 64;

    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++)
            for (int c = 0; c < 4; c++)
                for (int d = 0; d < 4; d++)
                    for (int e = 0; e < 2; e++) {
                        all_mv8x8[a][b][c][d][e] = (a + b + c + d + e) % 32767;
                        pred_mv8x8[a][b][c][d][e] = (a + b + c + d + e + 1) % 32767;
                    }

    all_mv = (short ******)calloc(ii, sizeof(short *****));
    pred_mv = (short ******)calloc(ii, sizeof(short *****));

    for (int i_idx = 0; i_idx < ii; i_idx++) {
        all_mv[i_idx] = (short *****)calloc(jj, sizeof(short ****));
        pred_mv[i_idx] = (short *****)calloc(jj, sizeof(short ****));
        for (int j_idx = 0; j_idx < jj; j_idx++) {
            all_mv[i_idx][j_idx] = (short ****)calloc(2, sizeof(short ***));
            pred_mv[i_idx][j_idx] = (short ****)calloc(2, sizeof(short ***));
            for (int k = 0; k < 2; k++) {
                all_mv[i_idx][j_idx][k] = (short ***)calloc(2, sizeof(short **));
                pred_mv[i_idx][j_idx][k] = (short ***)calloc(2, sizeof(short **));
                for (int l = 0; l < 2; l++) {
                    all_mv[i_idx][j_idx][k][l] = (short **)calloc(2, sizeof(short *));
                    pred_mv[i_idx][j_idx][k][l] = (short **)calloc(2, sizeof(short *));
                    for (int m = 0; m < 2; m++) {
                        all_mv[i_idx][j_idx][k][l][m] = (short *)calloc(2, sizeof(short));
                        pred_mv[i_idx][j_idx][k][l][m] = (short *)calloc(2, sizeof(short));
                    }
                }
            }
        }
    }
}