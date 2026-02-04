#include <stdio.h>
#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

int i;
int j;
int _usr_j1;
int m5[4];
int m4[4][4];
Boolean lossless_qpprime;

void init_vars() {
    i = 0;
    j = 0;
    _usr_j1 = 0;
    lossless_qpprime = FALSE;

    for (int idx_i = 0; idx_i < 4; idx_i++) {
        for (int idx_j = 0; idx_j < 4; idx_j++) {
            m4[idx_i][idx_j] = (idx_i * 4 + idx_j) + 1;
        }
    }

    for (int idx = 0; idx < 4; idx++) {
        m5[idx] = 0;
    }
}