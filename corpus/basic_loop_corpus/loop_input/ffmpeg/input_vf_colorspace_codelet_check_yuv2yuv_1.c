#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int n;
int16_t (*offset)[8];
int16_t (*coeff)[3][8];

void init_vars() {
    offset = aligned_alloc(32, sizeof(*offset) * 2);
    coeff = aligned_alloc(32, sizeof(*coeff) * 3);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
            offset[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 8; k++) {
                coeff[i][j][k] = 0;
            }
        }
    }
}