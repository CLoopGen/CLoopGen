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
int m4[4][4];
Boolean lossless_qpprime;

void init_vars() {
    i = 0;
    j = 0;
    i1 = 0;
    lossless_qpprime = FALSE;

    for (int idx = 0; idx < 4; idx++) {
        m5[idx] = 0;
        for (int jdx = 0; jdx < 4; jdx++) {
            m4[idx][jdx] = (idx + 1) * (jdx + 1);
        }
    }
}