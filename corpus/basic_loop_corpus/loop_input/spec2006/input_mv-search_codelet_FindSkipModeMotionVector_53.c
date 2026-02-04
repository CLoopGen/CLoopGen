#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int bx;
int by;
short ******all_mv;
short pmv[2];

void init_vars() {
    pmv[0] = 100;
    pmv[1] = 200;

    all_mv = (short ******)calloc(4, sizeof(short *****));
    for (int i = 0; i < 4; i++) {
        all_mv[i] = (short *****)calloc(4, sizeof(short ****));
        for (int j = 0; j < 4; j++) {
            all_mv[i][j] = (short ****)calloc(1, sizeof(short ***));
            for (int k = 0; k < 1; k++) {
                all_mv[i][j][k] = (short ***)calloc(1, sizeof(short **));
                for (int l = 0; l < 1; l++) {
                    all_mv[i][j][k][l] = (short **)calloc(1, sizeof(short *));
                    for (int m = 0; m < 1; m++) {
                        all_mv[i][j][k][l][m] = (short *)calloc(2, sizeof(short));
                    }
                }
            }
        }
    }
}