#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *lsfq;
int lp_order = 65536;
int i;
int j;

void init_vars() {
    lsfq = (int16_t*)aligned_alloc(_Alignof(int16_t), lp_order * sizeof(int16_t));
    for (int idx = 0; idx < lp_order; idx++) {
        lsfq[idx] = (int16_t)(lp_order - idx);
    }
}