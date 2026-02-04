#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int size;
int buckets[4][256];
int i;
int j;

void init_vars() {
    size = 1 << 20;
    for (int j_idx = 0; j_idx < 4; j_idx++) {
        for (int i_idx = 0; i_idx < 256; i_idx++) {
            buckets[j_idx][i_idx] = rand() % 1000 + 1;
        }
    }
    i = 0;
    j = 0;
}