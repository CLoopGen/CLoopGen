#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w2;
int x;
int16_t *b;
int16_t *tmp;

void init_vars() {
    w2 = 65536;  // Size to achieve ~0.01 sec runtime on modern CPU

    b = (int16_t*)aligned_alloc(32, sizeof(int16_t) * (w2 * 3));
    tmp = (int16_t*)aligned_alloc(32, sizeof(int16_t) * (w2 + 4));

    for (int i = 0; i < w2 + 4; i++) {
        tmp[i] = (int16_t)(i % 32767);
    }

    for (int i = 0; i < w2 * 3; i++) {
        b[i] = (int16_t)((i * 7) % 32767);
    }
}