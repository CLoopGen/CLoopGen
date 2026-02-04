#include <stdio.h>
#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

int i;
int j;
int _usr_j1;
int M4[4][4];
int M5[4];
Boolean lossless_qpprime;

void init_vars() {
    i = 0;
    j = 0;
    _usr_j1 = 0;
    lossless_qpprime = FALSE;

    for (int idx1 = 0; idx1 < 4; idx1++) {
        for (int idx2 = 0; idx2 < 4; idx2++) {
            M4[idx1][idx2] = (idx1 + 1) * (idx2 + 1);
        }
    }

    for (int idx = 0; idx < 4; idx++) {
        M5[idx] = 0;
    }
}