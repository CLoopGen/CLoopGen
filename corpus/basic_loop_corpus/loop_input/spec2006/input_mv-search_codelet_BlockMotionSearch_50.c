#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int blocktype = 1;
short mv_x = 10;
short mv_y = 20;
int i;
int j;
int block_x = 0;
int block_y = 0;
int bsx = 64;
int bsy = 64;
short bimv_x = -10;
short bimv_y = -20;
short iterlist = 0;

short ******bipred_mv;

void init_vars() {
    int dim0 = 16;
    int dim1 = 16;
    int dim2 = 2;
    int dim3 = 1;
    int dim4 = 2;
    int dim5 = 2;

    bipred_mv = (short ******)calloc(dim0, sizeof(short *****));
    for (int a = 0; a < dim0; a++) {
        bipred_mv[a] = (short *****)calloc(dim1, sizeof(short ****));
        for (int b = 0; b < dim1; b++) {
            bipred_mv[a][b] = (short ****)calloc(dim2, sizeof(short ***));
            for (int c = 0; c < dim2; c++) {
                bipred_mv[a][b][c] = (short ***)calloc(dim3, sizeof(short **));
                for (int d = 0; d < dim3; d++) {
                    bipred_mv[a][b][c][d] = (short **)calloc(dim4, sizeof(short *));
                    for (int e = 0; e < dim4; e++) {
                        bipred_mv[a][b][c][d][e] = (short *)calloc(dim5, sizeof(short));
                    }
                }
            }
        }
    }

    block_x = 0;
    block_y = 0;
    bsx = 64;
    bsy = 64;
    blocktype = 1;
    iterlist = 0;
    mv_x = 10;
    mv_y = 20;
    bimv_x = -10;
    bimv_y = -20;
}