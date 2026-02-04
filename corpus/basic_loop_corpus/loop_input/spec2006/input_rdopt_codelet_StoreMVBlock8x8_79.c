#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

short all_mv8x8[2][2][4][4][2];
short pred_mv8x8[2][2][4][4][2];
int dir = 1;
int mode = 1;
int ref = 1;
int i;
int j;
int i0 = 0;
int _usr_j0 = 0;
int ii = 4;
int jj = 4;

short ******all_mv;
short ******pred_mv;

#define j0 _usr_j0

void init_vars() {
    const int dim1 = 4;
    const int dim2 = 4;
    const int dim3 = 2;
    const int dim4 = 2;
    const int dim5 = 2;
    const int dim6 = 2;

    all_mv = (short ******)calloc(dim1, sizeof(short *****));
    pred_mv = (short ******)calloc(dim1, sizeof(short *****));

    for (int a = 0; a < dim1; a++) {
        all_mv[a] = (short *****)calloc(dim2, sizeof(short ****));
        pred_mv[a] = (short *****)calloc(dim2, sizeof(short ****));
        for (int b = 0; b < dim2; b++) {
            all_mv[a][b] = (short ****)calloc(dim3, sizeof(short ***));
            pred_mv[a][b] = (short ****)calloc(dim3, sizeof(short ***));
            for (int c = 0; c < dim3; c++) {
                all_mv[a][b][c] = (short ***)calloc(dim4, sizeof(short **));
                pred_mv[a][b][c] = (short ***)calloc(dim4, sizeof(short **));
                for (int d = 0; d < dim4; d++) {
                    all_mv[a][b][c][d] = (short **)calloc(dim5, sizeof(short *));
                    pred_mv[a][b][c][d] = (short **)calloc(dim5, sizeof(short *));
                    for (int e = 0; e < dim5; e++) {
                        all_mv[a][b][c][d][e] = (short *)calloc(dim6, sizeof(short));
                        pred_mv[a][b][c][d][e] = (short *)calloc(dim6, sizeof(short));
                        for (int f = 0; f < dim6; f++) {
                            all_mv[a][b][c][d][e][f] = rand() % 1000;
                            pred_mv[a][b][c][d][e][f] = rand() % 1000;
                        }
                    }
                }
            }
        }
    }

    dir = 1;
    mode = 1;
    ref = 1;
    i0 = 0;
    _usr_j0 = 0;
    ii = 4;
    jj = 4;
}