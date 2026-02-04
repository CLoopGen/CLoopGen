#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

double block1[64];
double s;
int i;
int j;
int16_t *block;

void init_vars() {
    s = 0.5;
    size_t total_size = 1 << 20;
    block = (int16_t *)aligned_alloc(64, total_size * sizeof(int16_t));
    if (!block) {
        exit(1);
    }
    for (size_t idx = 0; idx < total_size; idx++) {
        block[idx] = (int16_t)(idx % 512);
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}