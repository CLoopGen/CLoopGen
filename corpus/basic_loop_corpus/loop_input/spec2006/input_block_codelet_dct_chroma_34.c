#include <stdio.h>
#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

int i;
int j;
int i1;
int m5[4];
int m6[4];
int m4[4][4];
Boolean lossless_qpprime;

void init_vars() {
    i = 0;
    j = 0;
    i1 = 0;
    lossless_qpprime = FALSE;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            m4[row][col] = (row * 4 + col) * 7 + 1;
        }
    }

    for (int idx = 0; idx < 4; idx++) {
        m5[idx] = idx * 3;
        m6[idx] = idx * 5;
    }
}