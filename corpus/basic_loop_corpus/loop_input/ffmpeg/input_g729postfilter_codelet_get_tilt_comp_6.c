#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int16_t *lp_gn;
int i;
int gain_term;

void init_vars() {
    const size_t total_size = 256 * 1024 * sizeof(int16_t);
    lp_gn = (int16_t *)aligned_alloc(32, total_size);
    if (!lp_gn) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_size / sizeof(int16_t); ++idx) {
        lp_gn[idx] = rand() % 65536 - 32768;
    }

    i = 0;
    gain_term = 0;
}