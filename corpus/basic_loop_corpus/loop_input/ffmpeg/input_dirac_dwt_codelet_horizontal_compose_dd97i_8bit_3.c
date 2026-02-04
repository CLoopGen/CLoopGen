#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int w2 = 16384;
int16_t *b;
int16_t *tmp;

void init_vars() {
    b = aligned_alloc(32, (w2 + w2) * sizeof(int16_t));
    tmp = aligned_alloc(32, w2 * sizeof(int16_t));

    for (int i = 0; i < w2 + w2; i++) {
        b[i] = rand() % 1000;
    }
    for (int i = 0; i < w2; i++) {
        tmp[i] = 0;
    }
}