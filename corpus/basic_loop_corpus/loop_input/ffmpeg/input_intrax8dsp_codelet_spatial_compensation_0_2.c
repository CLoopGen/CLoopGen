#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint16_t left_sum[2][8];
uint16_t top_sum[2][8];

void init_vars() {
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 8; k++) {
            top_sum[j][k] = (j + 1) * (k + 1) * 7;
            left_sum[j][k] = (j + 1) * (k + 1) * 13;
        }
    }
    i = 0;
}