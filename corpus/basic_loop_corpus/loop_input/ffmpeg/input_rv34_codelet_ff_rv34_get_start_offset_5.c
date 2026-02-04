#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t rv34_mb_max_sizes[6] = {0};
int mb_size = 0;
int i = 0;

void init_vars() {
    mb_size = 256;
    for (int idx = 0; idx < 6; idx++) {
        rv34_mb_max_sizes[idx] = (idx + 1) * 64;
    }
}