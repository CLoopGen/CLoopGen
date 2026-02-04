#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

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

short ******all_mv = NULL;
short ******pred_mv = NULL;

#define j0 _usr_j0

void init_vars() {
    ii = 64;
    jj = 64;
    i0 = 0;
    _usr_j0 = 0;
    dir = 0;
    mode = 0;
    ref = 0;
    bw_ref = 0;

    all_mv = (short ******)malloc(ii * sizeof(short *****));
    if (!all_mv) exit(1);
    pred_mv = (short ******)malloc(ii * sizeof(short *****));
    if (!pred_mv) exit(1);

    for (int i_idx = 0; i_idx < ii; i_idx++) {
        all_mv[i_idx] = (short *****)malloc(jj * sizeof(short ****));
        if (!all_mv[i_idx]) exit(1);
        pred_mv[i_idx] = (short *****)malloc(jj * sizeof(short ****));
        if (!pred_mv[i_idx]) exit(1);

        for (int j_idx = 0; j_idx < jj; j_idx++) {
            all_mv[i_idx][j_idx] = (short ****)malloc(2 * sizeof(short ***));
            if (!all_mv[i_idx][j_idx]) exit(1);
            pred_mv[i_idx][j_idx] = (short ****)malloc(2 * sizeof(short ***));
            if (!pred_mv[i_idx][j_idx]) exit(1);

            for (int k = 0; k < 2; k++) {
                all_mv[i_idx][j_idx][k] = (short ***)malloc(256 * sizeof(short **));
                if (!all_mv[i_idx][j_idx][k]) exit(1);
                pred_mv[i_idx][j_idx][k] = (short ***)malloc(256 * sizeof(short **));
                if (!pred_mv[i_idx][j_idx][k]) exit(1);

                for (int m = 0; m < 256; m++) {
                    all_mv[i_idx][j_idx][k][m] = (short **)malloc(2 * sizeof(short *));
                    if (!all_mv[i_idx][j_idx][k][m]) exit(1);
                    pred_mv[i_idx][j_idx][k][m] = (short **)malloc(2 * sizeof(short *));
                    if (!pred_mv[i_idx][j_idx][k][m]) exit(1);

                    for (int n = 0; n < 2; n++) {
                        all_mv[i_idx][j_idx][k][m][n] = (short *)calloc(2, sizeof(short));
                        if (!all_mv[i_idx][j_idx][k][m][n]) exit(1);
                        pred_mv[i_idx][j_idx][k][m][n] = (short *)calloc(2, sizeof(short));
                        if (!pred_mv[i_idx][j_idx][k][m][n]) exit(1);
                    }
                }
            }
        }
    }

    for (int d = 0; d < 2; d++)
        for (int a = 0; a < 2; a++)
            for (int b = 0; b < 4; b++)
                for (int c = 0; c < 4; c++)
                    for (int e = 0; e < 2; e++) {
                        all_mv8x8[d][a][b][c][e] = (short)(d + a + b + c + e);
                        pred_mv8x8[d][a][b][c][e] = (short)(d + a + b + c + e);
                    }
}