#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *synt_denum;
int k;
int16_t numerator[11];

void init_vars() {
    synt_denum = (int16_t*)aligned_alloc(_Alignof(int16_t), 11 * sizeof(int16_t));
    for (int i = 0; i < 11; i++) {
        synt_denum[i] = (int16_t)(i + 1);
    }
}