#include <stdint.h>
#include <string.h>

int i;
int j;
int i1;
int m5[4];
int predicted_block[4][4];

void init_vars() {
    for (int idx = 0; idx < 4; idx++) {
        m5[idx] = 1 + idx;
        for (int jdx = 0; jdx < 4; jdx++) {
            predicted_block[idx][jdx] = (idx + 1) * (jdx + 1);
        }
    }
}