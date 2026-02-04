#include <stdint.h>

short all_mv8x8[2][2][4][4][2];
int dir = 0;
int i;
int j;
int i0 = 0;
int _usr_j0 = 0;
int ii = 4;
int jj = 4;

void init_vars() {
    for (int d = 0; d < 2; d++) {
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 4; b++) {
                for (int c = 0; c < 4; c++) {
                    for (int e = 0; e < 2; e++) {
                        all_mv8x8[d][a][b][c][e] = 0;
                    }
                }
            }
        }
    }
}