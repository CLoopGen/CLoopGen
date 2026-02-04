#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *a;
int32_t f[2][6];
int32_t tmp;
int i;

void init_vars() {
    a = aligned_alloc(32, sizeof(int16_t) * 12);
    for (int j = 0; j < 12; j++) {
        a[j] = 0;
    }
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 6; k++) {
            f[j][k] = (j + 1) * (k + 1) * 1000;
        }
    }
}