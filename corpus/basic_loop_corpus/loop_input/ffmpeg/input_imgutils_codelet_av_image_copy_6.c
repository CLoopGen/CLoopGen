#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int dst_linesizes[4] = {1024, 2048, 512, 128};
int src_linesizes[4] = {1024, 2048, 512, 128};
ptrdiff_t dst_linesizes1[4];
ptrdiff_t src_linesizes1[4];
int i;

void init_vars() {
    for (int j = 0; j < 4; j++) {
        dst_linesizes[j] = (j + 1) * 1024;
        src_linesizes[j] = (j + 1) * 512;
    }
}