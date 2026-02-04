#include <stdio.h>
#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

int i;
int j;
int ii;
int jj;
int i1;
int _usr_j1;

int M5[4];
int M0[4][4][4][4];

Boolean lossless_qpprime;

void init_vars() {
    int i_val, ii_val, j_val, jj_val;
    
    for (i_val = 0; i_val < 4; i_val++) {
        for (ii_val = 0; ii_val < 4; ii_val++) {
            for (j_val = 0; j_val < 4; j_val++) {
                for (jj_val = 0; jj_val < 4; jj_val++) {
                    M0[i_val][ii_val][j_val][jj_val] = (i_val + 1) * 1000 + (ii_val + 1) * 100 + (j_val + 1) * 10 + (jj_val + 1);
                }
            }
        }
    }

    for (int idx = 0; idx < 4; idx++) {
        M5[idx] = idx * 100;
    }

    i = 0;
    j = 0;
    ii = 0;
    jj = 0;
    i1 = 0;
    _usr_j1 = 0;

    lossless_qpprime = FALSE;
}