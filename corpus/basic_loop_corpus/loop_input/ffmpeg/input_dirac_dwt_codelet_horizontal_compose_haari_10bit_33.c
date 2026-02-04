#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *b;
int32_t *temp;
int w2;
int x;

void init_vars() {
    w2 = 65536; // Size such that total data is around 1MB per array

    b = (int32_t*)aligned_alloc(32, sizeof(int32_t) * w2 * 2);
    temp = (int32_t*)aligned_alloc(32, sizeof(int32_t) * w2 * 2);

    for (int i = 0; i < w2 * 2; i++) {
        b[i] = rand() % 1000;
    }

    for (int i = 0; i < w2 * 2; i++) {
        temp[i] = 0;
    }
}