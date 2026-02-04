#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *coef;
int y;
int x;

static int32_t *alloc_coef() {
    size_t size = 4 * 4 * sizeof(int32_t);
    int32_t *ptr = (int32_t *)calloc(1, size);
    if (!ptr) exit(1);
    return ptr;
}

void init_vars() {
    coef = alloc_coef();
    for (int i = 0; i < 4 * 4; i++) {
        coef[i] = rand() % 1000;
    }
    y = 0;
    x = 0;
}